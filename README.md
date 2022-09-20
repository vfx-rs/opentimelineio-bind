# opentimelineio-bind
Rust binding for [OpenTimelineIO library](https://github.com/PixarAnimationStudios/OpenTimelineIO)

The OpenTimelineIO crate is maintained by the [vfx-rs project](https://github.com/vfx-rs)



## Supported Platforms

OpenTimelineIO Rust binding is currently supported on Linux platforms.

## Dependencies

* Rust (1.56.1) https://www.rust-lang.org/
* libc (0.2) https://crates.io/crates/libc
* cc (1.0) https://crates.io/crates/cc
* pkg-config (0.3) https://crates.io/crates/pkg-config
* bindgen (0.53.1) https://crates.io/crates/bindgen

## Getting and Building the Code

1. Install Dependencies

2. Download the opentimelineio-bind source code
You can download source code using ```git``` to clone the repository.

```
> git clone https://github.com/vfx-rs/opentimelineio-bind.git
Cloning into 'opentimelineio-bind'...
```

3. Generate bindings
```
> cargo build
```

Testing

```bash
clear && LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/otio/lib:/opt/otio/lib64 cargo llvm-cov --html

```
