# LINUX Device Drivers:
### Learn About Makefile :

 1: [Open Source Link](https://opensourceforu.com/?s=device+driver)
 
 + -> [Same Author but Other Link](https://sysplay.github.io/books/LinuxDrivers/book/Content/Part13.html)
    
   + -> This link will provide you information about device drivers. It has nu mber of articals.
        I am still trying to read them then update more about this .....       
        What articals i have read in this series of Linux Device Drivers. i have mentioned them all.
        
   + -> To know about makefile  Read [this](http://opensourceforu.com/2012/06/gnu-make-in-detail-for-beginners)  
   
   + ->> [Rule for Making Makefile for driver](https://www.youtube.com/watch?v=Zn8mEZXr6nE)
   
    1 : $ vim Makefile
    
       --->>> Wite only one line 
              obj-m := testUSB.o
              
       --->>> Comeout from this Makefile
       
    /* Run make command as root user. A simple space can make your life hell and spend many hours. Above vedio must watch */
   
   2 : $ make -C /lib/modules/$(uname -r)/build M=$PWD modules
   
   3 : $ insmod <name of Driver.ko>
   4 : dmesg
   5 : $ rmmode <name of Driver.ko>
  ========================================================================   
  
 1 : Device Drivers, Part 1: Linux Device Drivers for Your Girl Friend
         
 2 : Device Drivers, Part 2: Writing Your First Linux Driver in the...
         
 3 : Device Drivers, Part 3: Kernel C Extras in a Linux Driver
         
 4 : Device Drivers, Part 4: Linux Character Drivers
         
 5 : Device Drivers, Part 5: Character Device Files — Creation & Operations
         
 6 : Device Drivers, Part 6: Decoding Character Device File Operations 
    [LINK](https://sysplay.in/index.php?pagefile=linux_drivers)
      
 7 : Device Drivers, Part 7: Generic Hardware Access in Linux
         
 8 : Device Drivers, Part 8: Accessing x86-Specific I/O-Mapped Hardware
         
   [LINK](https://github.com/esrijan/ddk-software/tree/fw/v2.2/LDDKFirmware/Code )
         
   [LINK](https://github.com/torvalds/linux/blob/master/include/uapi/linux/serial_reg.h )
         
   This is Actual device driver writeen from datasheet PC16550D.   
         
   [LINK](https://sysplay.in/blog/linux-device-drivers/2013/09/accessing-x86-specific-io-mapped-hardware-in-linux/)
         
 9 : Device Drivers, Part 9: I/O Control in Linux
        
10 : Device Drivers, Part 10: Kernel-Space Debuggers in Linux
        
11 : Device Drivers, Part 11: USB Drivers in Linux        
        
   [LINK](https://github.com/spotify/linux/blob/master/Documentation/usb/proc_usb_info.txt)        
                
12 : Device Drivers, Part 12: USB Drivers in Linux 

to check USB devices $cat /sys/bus/usb/devices/*/product
        
13 : [Device Drivers, Part 13: Data Transfer to and from USB Devices](https://opensourceforu.com/2011/12/data-transfers-to-from-usb-devices/)
        
14 : Device Drivers, Part 14: A Dive Inside the Hard Disk for Understanding Partitions
                ---- Not understood well again read
                
==============================================================================        
 2: https://www-user.tu-chemnitz.de/~heha/viewchm.php/hs/LinuxDeviceDrivers3.chm/
 
 3: http://haifux.org/lectures/86-sil/kernel-modules-drivers/node14.html#h
 
 4: [TU Delf University Documents Link](http://epic-alfa.kavli.tudelft.nl/share/doc/kernel-doc-2.6.32/Documentation/DocBook/usb/)
 
 5: [LINUX DEVICE DRIVERS BOOK](https://www.oreilly.com/library/view/linux-device-drivers/0596005903/ch13.html)
