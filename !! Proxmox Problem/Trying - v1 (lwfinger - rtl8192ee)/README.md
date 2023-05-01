# !!!!!!!!  
# ! FAIL !  
# !!!!!!!!  


# As [example lwfinger/rtl8192ee](https://github.com/lwfinger/rtl8192ee) 

root@pve: git clone https://github.com/lwfinger/rtl8192ee
root@pve: cd rtl8192ee

## Compiling

Depending on your distribution, you might need to run this as root.

root@pve:~/rtl8192ee# sudo make all

## Installing

``` console
root@pve:~/rtl8192ee# sudo make install
install -p -m 644 8192ee.ko  /lib/modules/5.15.107-1-pve/kernel/drivers/net/wireless/
/sbin/depmod -a 5.15.107-1-pve

You must also blacklist the kernel driver, or it will override this one.

root@pve: echo "blacklist rtl8821ae" | sudo tee -a /etc/modprobe.d/pve-blacklist.conf

root@pve: cat ~/../etc/modprobe.d/pve-blacklist.conf
# This file contains a list of modules which are not supported by Proxmox VE

# nidiafb see bugreport https://bugzilla.proxmox.com/show_bug.cgi?id=701
blacklist nvidiafb
blacklist rtl8821ae
```

Now, tell the system to load the module on boot.
```console
root@pve:~/rtl8192ee# echo "8192ee" | sudo tee -a ~/../etc/modules-load.d/modules.conf
8192ee
root@pve:~/rtl8192ee# cat  ~/../etc/modules-load.d/modules.conf
                # /etc/modules: kernel modules to load at boot time.
                #
                # This file contains the names of kernel modules that should be loaded
                # at boot time, one per line. Lines beginning with "#" are ignored.

                8192ee

root@pve:~/rtl8192ee# sudo reboot
```