SUMMARY = "Read only rootfs with overlay init script"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"
DEPENDS = "virtual/kernel"
SRC_URI = "file://init-readonly-rootfs-overlay-boot.sh file://atcc.rofs"

S = "${WORKDIR}"

# atcc.rofs depends on bash
RDEPENDS:${PN} += "bash"

do_install() {
        install -d ${D}/usr/bin/
        install -m 0500 ${WORKDIR}/atcc.rofs ${D}/usr/bin/
        install -m 0755 ${WORKDIR}/init-readonly-rootfs-overlay-boot.sh ${D}/init
        install -d "${D}/media/rfs/ro"
        install -d "${D}/media/rfs/rw"
}

FILES:${PN} += " /init /media/rfs /usr/bin"

# Due to kernel dependency
PACKAGE_ARCH = "${MACHINE_ARCH}"
