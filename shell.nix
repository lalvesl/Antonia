{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = with pkgs; [
    clang
    lldb
    cmake
    gnumake
    pkg-config
    arduino-cli
    avrdude
    clang-tools
  ];

  shellHook = '''';
}
