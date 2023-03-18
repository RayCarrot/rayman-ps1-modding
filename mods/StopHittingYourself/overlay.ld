__heap_base = __ovr_end;

__ovr_start = 0x8016ca80;

SECTIONS {
    OVERLAY __ovr_start : SUBALIGN(4) {
        .srcdummyc {
            . = . + 0x53274;
            KEEP(src/dummy.o(.text*))
            KEEP(src/dummy.o(.rodata*))
            KEEP(src/dummy.o(.sdata*))
            KEEP(src/dummy.o(.data*))
            KEEP(src/dummy.o(.sbss*))
            KEEP(src/dummy.o(.bss*))
            . = ALIGN(4);
            __ovr_end = .;
        }
        .srcstophittingyourselfc {
            . = . + 0x5327c;
            KEEP(src/stophittingyourself.o(.text*))
            KEEP(src/stophittingyourself.o(.rodata*))
            KEEP(src/stophittingyourself.o(.sdata*))
            KEEP(src/stophittingyourself.o(.data*))
            KEEP(src/stophittingyourself.o(.sbss*))
            KEEP(src/stophittingyourself.o(.bss*))
            . = ALIGN(4);
            __ovr_end = .;
        }
        .srchook_dopoing_switchofffists {
            KEEP(src/hook_dopoing_switchofffist.o(.text*))
            KEEP(src/hook_dopoing_switchofffist.o(.rodata*))
            KEEP(src/hook_dopoing_switchofffist.o(.sdata*))
            KEEP(src/hook_dopoing_switchofffist.o(.data*))
            KEEP(src/hook_dopoing_switchofffist.o(.sbss*))
            KEEP(src/hook_dopoing_switchofffist.o(.bss*))
            . = ALIGN(4);
            __ovr_end = .;
        }
    }
}
