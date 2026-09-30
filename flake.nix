{
  description = "PQRV dev shell: XuanTie 900 multilib RISC-V cross toolchain";

  inputs.nixpkgs.url = "nixpkgs/nixpkgs-unstable";

  outputs = { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };

      # nixpkgs' riscv64 cross gcc is single-ABI (lp64d only). This project also
      # builds ilp32 and lp64, so it needs the multilib XuanTie toolchain named
      # in the README -- which is the compiler the paper's numbers came from.
      xuantie = pkgs.stdenvNoCC.mkDerivation {
        pname = "xuantie-900-gcc-linux-glibc";
        version = "2.8.0";

        src = pkgs.fetchurl {
          url = "https://occ-oss-prod.oss-cn-hangzhou.aliyuncs.com/resource//1698113812618/Xuantie-900-gcc-linux-5.10.4-glibc-x86_64-V2.8.0-20231018.tar.gz";
          hash = "sha256-UCSanRePuD6jqstFt3mtPxmBmzFYnr1SfQANl4cS4Ss=";
        };

        nativeBuildInputs = [ pkgs.autoPatchelfHook ];
        buildInputs = [ pkgs.stdenv.cc.cc.lib pkgs.zlib ];

        # Never strip: most of the tree is RISC-V target objects.
        dontStrip = true;

        installPhase = "mkdir -p $out && cp -a ./* $out/";
      };
    in
    {
      devShells.${system}.default = pkgs.mkShell { packages = [ xuantie ]; };
    };
}
