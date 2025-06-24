!!include <main.kl>

69 USAGE {
  name** NAME = "Nucleo POS"
  get a, 0 :: __authors __name
}

72 BOOT {
  GOT* bootloader = path("./boot")
  if (000.booted() == 1) {
    run EXEC** (c, int** argc, argv) :: bootloader
    init run -- path("./" -- ++ "/")
  }
}

73 VIDEO {
  !send BOOT :: bootloader +- run
  2 * 2 + 2

  !send __msg_contactor=drivers :: video_load
  !send pixel() :: video_drive
}
