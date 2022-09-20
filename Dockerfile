FROM aswf/ci-otio:2022.2

ARG USERNAME=vfxrs
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME && \
    echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME && \
    chmod 0440 /etc/sudoers.d/$USERNAME

# Install Rust
ENV RUSTUP_HOME=/usr/local/rustup \
    CARGO_HOME=/usr/local/cargo \
    PATH=/usr/local/cargo/bin:$PATH \
    RUST_VERSION=1.63.0 \
    RUST_ARCH=x86_64-unknown-linux-gnu \
    RUST_ANALYZER_VERSION=2022-09-12
RUN curl -O "https://static.rust-lang.org/rustup/archive/1.25.1/${RUST_ARCH}/rustup-init" && \
    chmod +x rustup-init && \
    ./rustup-init -y --no-modify-path --profile default --default-toolchain $RUST_VERSION --default-host ${RUST_ARCH} && \
    rm rustup-init && \
    chmod -R a+w $RUSTUP_HOME $CARGO_HOME && \
    chgrp -R $USERNAME $RUSTUP_HOME $CARGO_HOME && \
    rustup --version && \
    cargo --version && \
    rustc --version

# Install Rust Analyzer
RUN cd /tmp && \
    git clone https://github.com/rust-lang/rust-analyzer.git && \
    cd rust-analyzer && \
    git checkout $RUST_ANALYZER_VERSION && \
    cargo xtask install --server && \
    cd ../ && \
    rm -rf rust-analyzer
# Gets installed to /usr/local/cargo/bin/rust-analyzer

# # Compile OpenTimelineIO
ENV OTIO_VERSION=v0.14.1 \
    COTIO_VERSION=9745fe5911d3d6495184da1ce3a6efba1d68b389
RUN mkdir -p /tmp/otio
# Compile OpenTimelineIO C bindings
RUN cd /tmp/otio && \
    git clone --recurse-submodules https://github.com/OpenTimelineIO/OpenTimelineIO-C-Bindings.git && \
    cd OpenTimelineIO-C-Bindings && \
    git checkout $COTIO_VERSION && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_INSTALL_PREFIX=/opt/otio -DCOTIO_SHARED_LIBS=ON ../ && \
    make -j $(nproc --all) && \
    make install && \
    cp /tmp/otio/OpenTimelineIO-C-Bindings/include/copentimelineio/typeInfo.h /opt/otio/include/copentimelineio/typeInfo.h
# Cleanup
RUN rm -rf /tmp/otio

ENV LD_LIBRARY_PATH=/usr/local/lib:/usr/local/lib64:$LD_LIBRARY_PATH

# Add useful tools
RUN rustup component add llvm-tools-preview && \
    cargo install bindgen && \
    cargo install cargo-valgrind && \
    cargo install cargo-llvm-cov

USER $USERNAME
