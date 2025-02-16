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
    nodejs
  ];

  shellHook = ''
    node -e "console.log(Array.from({length: 1024}, (_,i)=>i*(Math.PI/(2*1024))).map(i=>Math.sin(i)).map(i=>i*2*1024).map(i=>Math.round(i)).map(i=>i.toString(16)).map(h=>h.padStart(4, '0')).map(h=>'0x'+h).join(', '))" > sin.txt
  '';
}
