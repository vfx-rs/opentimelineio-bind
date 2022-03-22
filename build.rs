extern crate bindgen;

use std::path::PathBuf;
use std::{env, path::Path};
use std::process::Command;

fn main() {
   
  let opentimeline_dir =
    env::var("OPENTIMELINE_DIR").expect("'OPENTIMELINE_DIR' envvar is not defined");
  let opentimeline_lib_path = Path::new(&opentimeline_dir).join("lib");
  let opentimeline_include_path =
    Path::new(&opentimeline_dir).join("include").join("opentimelineio");
   
  let copentime_dir = 
    env::var("COPENTIME_DIR").expect("'COPENTIME_DIR' envvar is not defined");
  let copentime_lib_path = Path::new(&copentime_dir).join("lib");
  let copentime_include_path =
    Path::new(&copentime_dir).join("include").join("copentime");

  let copentimeline_dir = 
    env::var("COPENTIMELINE_DIR").expect("'COPENTIMELINE_DIR' envvar is not defined");
  let copentimeline_lib_path = Path::new(&copentimeline_dir).join("lib");
  let copentimeline_include_path = 
    Path::new(&copentimeline_dir).join("include").join("copentimelineio");

  println!("cargo:rerun-if-changed=build.rs");
  
  println!("cargo:rustc-link-search=native={}", opentimeline_lib_path.display()); // the "-L" flag
  println!("cargo:rustc-link-lib=dylib=opentimelineio"); // the "-l" flag

  println!("cargo:rustc-link-search=native={}", copentime_lib_path.display());
  println!("cargo:rustc-link-lib=static=copentime");

  println!("cargo:rustc-link-search=native={}", copentimeline_lib_path.display());
  println!("cargo:rustc-link-lib=static=copentimelineio");

  let bindings = bindgen::Builder::default()
    .header("wrapper.h")
    .allowlist_function("*")
    .allowlist_type("*")
    .allowlist_var("*")
    .generate()
    // Unwrap the Result and panic on failure.
    .expect("Unable to generate bindings");
  

  // Write the bindings to the $OUT_DIR/bindings.rs file.
  let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());

  bindings
    .write_to_file(out_path.join("bindings.rs"))
    .expect("Couldn't write bindings!");
}
