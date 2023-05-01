# !!!!!!!!  
# ! FAIL !  
# !!!!!!!!  


## Chip-Set: Realtek  

As example was used: [Chip-Set: Realtek RTL8111G not working](https://forum.proxmox.com/threads/chip-set-realtek-rtl8111g-not-working.108326/)  
Linux files: https://github.com/Ivan2navI/rtl8812ae/tree/main/Linux/rtl8812AE_linux_v4.3.2_12208.20140903 

And modify `dkms.conf`  
```console
PACKAGE_NAME="8812ae"
PACKAGE_VERSION="12208.20140903"
BUILT_MODULE_NAME[0]="$PACKAGE_NAME"
DEST_MODULE_LOCATION[0]="/updates/dkms"
AUTOINSTALL="YES"
REMAKE_INITRD="YES"
```

Git clone, go to `src`:
```console 

sudo apt install git net-tools wireless-tools wpasupplicant

root@pve:~# cd ~

root@pve:~# git clone https://github.com/Ivan2navI/rtl8812ae.git

# ! Create folder on proxmox and copy the "src" folder into it
root@pve:~# sudo cp -r ~/./rtl8812ae/\!\!\ Proxmox\ Problem/Trying\ -\ v2\ \(Chip-Set\ Realtek\)/files/* ~/../usr/src

# ! Install dkms
root@pve:~# sudo apt install -y dkms

# ! Update source.list and get pve-headers
root@pve:~# nano ~/../etc/apt/sources.list

# PVE pve-no-subscription repository provided by proxmox.com,
# NOT recommended for production use
# deb http://ftp.debian.org/debian bullseye main contrib non-free

deb http://download.proxmox.com/debian/pve bullseye pve-no-subscription

# ! Then install headers
# root@pve:~# apt search pve-headers
# apt list --installed | grep headers
# root@pve:~# sudo apt install pve-headers-$(uname -r)
root@pve:~# sudo apt install linux-headers-5.15.107-1-pve


# ! Adding new driver to kernel

root@pve:~# cd ~/../usr/src

sudo dkms add -m r8812ae -v 12208.20140903
        Error! Your kernel headers for kernel 5.15.107-1-pve cannot be found.
        Please install the linux-headers-5.15.107-1-pve package,
        or use the --kernelsourcedir option to tell DKMS where it's located

root@pve:/usr/src# apt list --installed | grep headers

        WARNING: apt does not have a stable CLI interface. Use with caution in scripts.

        linux-headers-5.10.0-22-amd64/stable,now 5.10.178-3 amd64 [installed,automatic]
        linux-headers-5.10.0-22-common/stable,now 5.10.178-3 all [installed,automatic]
        linux-headers-amd64/stable,now 5.10.178-3 amd64 [installed,automatic]
        pve-headers-5.15.107-1-pve/stable,now 5.15.107-1 amd64 [installed]
        pve-headers-5.15/stable,now 7.4-2 all [installed,automatic]
        pve-headers/stable,now 7.4-1 all [installed]

root@pve:/usr/src# uname -a
        Linux pve 5.15.107-1-pve #1 SMP PVE 5.15.107-1 (2023-04-20T10:05Z) x86_64 GNU/Linux



sudo dkms build -m r8812ae -v 12208.20140903

        Kernel preparation unnecessary for this kernel.  Skipping...

        Building module:
        cleaning build area...
        make -j4 KERNELRELEASE=5.15.107-1-pve -C /lib/modules/5.15.107-1-pve/build M=/var/lib/dkms/8812ae/12208.20140903/build...
        Error!  Build of 8812ae.ko failed for: 5.15.107-1-pve (x86_64)
        Make sure the name of the generated module is correct and at the root of the
        build directory, or consult make.log in the build directory
        /var/lib/dkms/8812ae/12208.20140903/build/ for more information.



sudo dkms install -m 8812ae -v 12208.20140903

```
