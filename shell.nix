with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "cpp-env";
  nativeBuildInputs = [
    clang
    clang-tools
    cmake
  ];
  buildInputs = [
    boost
    poco
  ];
}
