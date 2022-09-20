fn main() {
    // TODO: Use proper way to get the search paths and libraries.
    println!("cargo:rustc-link-search=native=/opt/otio/lib");
    println!("cargo:rustc-link-search=native=/opt/otio/lib64");
    println!("cargo:rustc-link-lib=dylib=copentime");
    println!("cargo:rustc-link-lib=dylib=copentimelineio");
}
