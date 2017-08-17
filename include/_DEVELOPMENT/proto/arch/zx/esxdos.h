include(__link__.m4)

#ifndef __ESXDOS_H__
#define __ESXDOS_H__

#include <arch.h>
#include <stdint.h>
#include <stddef.h>

// Limits

#define ESXDOS_PATH_MAX  __ESXDOS_PATH_MAX   // max pathname length in bytes including terminating \0
#define ESXDOS_NAME_MAX  __ESXDOS_NAME_MAX   // max filename length in bytes not including terminating \0

// Esxdos Drive Shortcuts

#define ESXDOS_DRIVE_CURRENT  __ESXDOS_DRIVE_CURRENT
#define ESXDOS_DRIVE_SYSTEM   __ESXDOS_DRIVE_SYSTEM

// Esxdos File Mode
// One file pointer per file, shared by both read and write actions

#define ESXDOS_MODE_R   __ESXDOS_MODE_READ
#define ESXDOS_MODE_W   __ESXDOS_MODE_WRITE

#define ESXDOS_MODE_OE  __ESXDOS_MODE_OPEN_EXIST       // open if file exists else error; fp = 0
#define ESXDOS_MODE_OC  __ESXDOS_MODE_OPEN_CREAT       // open if file exists else create; fp = 0

#define ESXDOS_MODE_CN  __ESXDOS_MODE_CREAT_NOEXIST    // if file exists error else create; fp = 0
#define ESXDOS_MODE_CT  __ESXDOS_MODE_CREAT_TRUNC      // create or replace an existing file; fp = 0

#define ESXDOS_MODE_P3  __ESXDOS_MODE_USE_HEADER

// Esxdos File Attribute Masks

#define ESXDOS_ATTR_RO   __ESXDOS_ATTR_READ_ONLY       // File is read-only
#define ESXDOS_ATTR_HID  __ESXDOS_ATTR_HIDDEN          // File should be hidden in some listings
#define ESXDOS_ATTR_SYS  __ESXDOS_ATTR_SYSTEM          // Ill-defined
#define ESXDOS_ATTR_VOL  __ESXDOS_ATTR_VOLUME_LABEL    // File stores volume label
#define ESXDOS_ATTR_DIR  __ESXDOS_ATTR_DIRECTORY       // File is a directory
#define ESXDOS_ATTR_AR   __ESXDOS_ATTR_ARCHIVE         // File has been modified so should be backed up

// Esxdos Seek Whence

#define ESXDOS_SEEK_SET  __ESXDOS_SEEK_SET   // set file pointer
#define ESXDOS_SEEK_FWD  __ESXDOS_SEEK_FWD   // forward from file pointer
#define ESXDOS_SEEK_BWD  __ESXDOS_SEEK_BWD   // backward from file pointer

// Esxdos Error Codes (can also be return value from dot commands to return error to basic)

#define ESXDOS_OK         __ESXDOS_OK                  // 0 OK 0:1
#define ESXDOS_EOK        __ESXDOS_EOK                 // O.K. ESXDOS, 0:1
#define ESXDOS_ENONSENSE  __ESXDOS_ENONSENSE           // Nonsense in ESXDOS, 0:1
#define ESXDOS_ESTEND     __ESXDOS_ESTEND              // Statement END error, 0:1
#define ESXDOS_EWRTYPE    __ESXDOS_EWRTYPE             // Wrong file TYPE, 0:1
#define ESXDOS_ENOENT     __ESXDOS_ENOENT              // No such FILE or DIR, 0:1
#define ESXDOS_EIO        __ESXDOS_EIO                 // I/O ERROR, 0:1
#define ESXDOS_EINVAL     __ESXDOS_EINVAL              // Invalid FILENAME, 0:1
#define ESXDOS_EACCES     __ESXDOS_EACCES              // Access DENIED, 0:1
#define ESXDOS_ENOSPC     __ESXDOS_ENOSPC              // Drive FULL, 0:1
#define ESXDOS_ENXIO      __ESXDOS_ENXIO               // Invalid I/O REQUEST, 0:1
#define ESXDOS_ENODRV     __ESXDOS_ENODRV              // No such DRIVE, 0:1
#define ESXDOS_ENFILE     __ESXDOS_ENFILE              // Too many OPEN FILES, 0:1
#define ESXDOS_EBADF      __ESXDOS_EBADF               // Bad file DESCRIPTOR, 0:1
#define ESXDOS_ENODEV     __ESXDOS_ENODEV              // No such DEVICE, 0:1
#define ESXDOS_EOVERFLOW  __ESXDOS_EOVERFLOW           // File pointer OVERFLOW, 0:1
#define ESXDOS_EISDIR     __ESXDOS_EISDIR              // Is a DIRECTORY, 0:1
#define ESXDOS_ENOTDIR    __ESXDOS_ENOTDIR             // Not a DIRECTORY, 0:1
#define ESXDOS_EEXIST     __ESXDOS_EEXIST              // File already EXISTS, 0:1
#define ESXDOS_EPATH      __ESXDOS_EPATH               // Invalid PATH, 0:1
#define ESXDOS_ENOSYS     __ESXDOS_ENOSYS              // No SYS, 0:1
#define ESXDOS_ENAMETOOLONG  __ESXDOS_ENAMETOOLONG     // Path too LONG, 0:1
#define ESXDOS_ENOCMD     __ESXDOS_ENOCMD              // No such COMMAND, 0:1
#define ESXDOS_EINUSE     __ESXDOS_EINUSE              // File in USE, 0:1
#define ESXDOS_ERDONLY    __ESXDOS_ERDONLY             // File is READ ONLY, 0:1

// these were not documented but were found in emulation

#define ESXDOS_EVERIFY      __ESXDOS_EVERIFY           // Verify FAILED, 0:1
#define ESXDOS_ELOADINGKO   __ESXDOS_ELOADINGKO        // Loading .KO FAILED, 0:1
#define ESXDOS_EDIRINUSE    __ESXDOS_EDIRINUSE         // Directory NOT EMPTY, 0:1
#define ESXDOS_EMAPRAMACTIVE  __ESXDOS_EMAPRAMACTIVE   // MAPRAM is ACTIVE, 0:1
#define ESXDOS_EDRIVEBUSY   __ESXDOS_EDRIVEBUSY        // Drive is BUSY, 0:1
#define ESXDOS_EFSUNKNOWN   __ESXDOS_EFSUNKNOWN        // Unknown FILESYSTEM, 0:1
#define ESXDOS_EDEVICEBUSY  __ESXDOS_EDEVICEBUSY       // Device is BUSY, 0:1

#define ESXDOS_EMAXCODE     __ESXDOS_EMAXCODE          // Largest valid error code

// Esxdos Data Structures

struct esxdos_device
{
   uint8_t  path;    // bits 7..3 = major, bits 2..0 = minor
   uint8_t  flags;
   uint32_t size;    // device size in blocks
};

struct esxdos_p3_hdr
{
   uint8_t  type;    // 0 = program, 1 = numeric array, 2 = char array, 3 = code
   uint16_t length;
   uint8_t  data[4];
   uint8_t  unused;
};

struct esxdos_stat
{
   uint8_t  drive;
   uint8_t  device;
   uint8_t  attr;
   uint32_t date;
   uint32_t size;
};

struct esxdos_dirent                      // <asciiz> file/dirname
{                                         // <byte>   attributes
   uint8_t  dir[__ESXDOS_NAME_MAX+1+9];   // <dword>  date
};                                        // <dword>  filesize

struct esxdos_dirent_slice
{
   uint8_t  attr;
   uint32_t date;
   uint32_t size;
};

//
// SELECT APPROPRIATE ESXDOS INTERFACE
//
// When esxdos is used from within esxdos, such as from dot commands,
// it expects parameters to be passed in the hl register pair.
//
// However when general programs use esxdos, it expects those same
// parameters to be passed in ix.
//
// To solve this, the toolchain indicates a dot command is being
// generated through -D__ESXDOS_DOT_COMMAND so that macros here can
// select the proper interface to esxdos automatically.
//
// Programs can also call the dot/ram versions of the esxdos interface
// directly if needed.
//

#ifdef __ESXDOS_DOT_COMMAND

// TOOLCHAIN IS GENERATING A DOT COMMAND

#define esxdos_disk_info     esxdos_dot_disk_info
#define esxdos_disk_read     esxdos_dot_disk_read
#define esxdos_disk_write    esxdos_dot_disk_write

#define esxdos_m_getdrv      esxdos_dot_m_getdrv
#define esxdos_m_setdrv      esxdos_dot_m_setdrv
#define esxdos_m_gethandle   esxdos_dot_m_gethandle
#define esxdos_m_getdate     esxdos_dot_m_getdate

#define esxdos_f_opendir     esxdos_dot_f_opendir
#define esxdos_f_opendir_p3  esxdos_dot_f_opendir_p3
#define esxdos_f_readdir     esxdos_dot_f_readdir
#define esxdos_f_getcwd      esxdos_dot_f_getcwd
#define esxdos_f_chdir       esxdos_dot_f_chdir
#define esxdos_f_unlink      esxdos_dot_f_unlink

#define esxdos_f_open        esxdos_dot_f_open
#define esxdos_f_open_p3     esxdos_dot_f_open_p3
#define esxdos_f_close       esxdos_dot_f_close
#define esxdos_f_sync        esxdos_dot_f_sync
#define esxdos_f_fstat       esxdos_dot_f_fstat
#define esxdos_f_fgetpos     esxdos_dot_f_fgetpos
#define esxdos_f_seek        esxdos_dot_f_seek
#define esxdos_f_read        esxdos_dot_f_read
#define esxdos_f_write       esxdos_dot_f_write

#else

// TOOLCHAIN IS NOT GENERATING A DOT COMMAND

#define esxdos_disk_info     esxdos_ram_disk_info
#define esxdos_disk_read     esxdos_ram_disk_read
#define esxdos_disk_write    esxdos_ram_disk_write

#define esxdos_m_getdrv      esxdos_ram_m_getdrv
#define esxdos_m_setdrv      esxdos_ram_m_setdrv
#define esxdos_m_gethandle   esxdos_ram_m_gethandle
#define esxdos_m_getdate     esxdos_ram_m_getdate

#define esxdos_f_opendir     esxdos_ram_f_opendir
#define esxdos_f_opendir_p3  esxdos_ram_f_opendir_p3
#define esxdos_f_readdir     esxdos_ram_f_readdir
#define esxdos_f_getcwd      esxdos_ram_f_getcwd
#define esxdos_f_chdir       esxdos_ram_f_chdir
#define esxdos_f_unlink      esxdos_ram_f_unlink

#define esxdos_f_open        esxdos_ram_f_open
#define esxdos_f_open_p3     esxdos_ram_f_open_p3
#define esxdos_f_close       esxdos_ram_f_close
#define esxdos_f_sync        esxdos_ram_f_sync
#define esxdos_f_fstat       esxdos_ram_f_fstat
#define esxdos_f_fgetpos     esxdos_ram_f_fgetpos
#define esxdos_f_seek        esxdos_ram_f_seek
#define esxdos_f_read        esxdos_ram_f_read
#define esxdos_f_write       esxdos_ram_f_write

#endif

// Translate ESXDOS Error Code to Library errno

__DPROTO(`b,c,d,e,iyl,iyh',`b,c,d,e,iyl,iyh',unsigned char,,errno_from_esxdos,unsigned char esxdos_error)

//
// ESXDOS FROM DOT COMMANDS
//

// Raw Disk IO on Specific Device

__DPROTO(,,int,,esxdos_dot_disk_info,unsigned char device,struct esx_device *ed)
__DPROTO(,,int,,esxdos_dot_disk_read,unsigned char device,uint32_t position,void *dst)
__DPROTO(,,int,,esxdos_dot_disk_write,unsigned char device,uint32_t position,void *src)

// Miscellaneous

__OPROTO(,,unsigned char,,esxdos_dot_m_getdrv,void)
__DPROTO(,,unsigned char,,esxdos_dot_m_setdrv,unsigned char drive)

__OPROTO(,,unsigned char,,esxdos_dot_m_gethandle,void)

__OPROTO(,,uint32_t,,esxdos_dot_m_getdate,void)

// Operations on Directories

__DPROTO(,,unsigned char,,esxdos_dot_f_opendir,void *pathname)
__DPROTO(,,unsigned char,,esxdos_dot_f_opendir_p3,void *pathname)
__DPROTO(,,unsigned char,,esxdos_dot_f_readdir,unsigned char handle,struct esx_dirent *dirent)

__DPROTO(,,int,,esxdos_dot_f_getcwd,void *buf)

__DPROTO(,,int,,esxdos_dot_f_chdir,void *pathname)

__DPROTO(,,int,,esxdos_dot_f_unlink,void *filename)

// Operations on Files

__DPROTO(,,unsigned char,,esxdos_dot_f_open,void *filename,unsigned char mode)
__DPROTO(,,unsigned char,,esxdos_dot_f_open_p3,void *filename,unsigned char mode,struct esx_p3_hdr *h)
__DPROTO(,,int,,esxdos_dot_f_close,unsigned char handle)

__DPROTO(,,int,,esxdos_dot_f_sync,unsigned char handle)
__DPROTO(,,int,,esxdos_dot_f_fstat,unsigned char handle,struct esx_stat *es)
__DPROTO(,,uint32_t,,esxdos_dot_f_fgetpos,unsigned char handle)

__DPROTO(,,uint32_t,,esxdos_dot_f_seek,unsigned char handle,uint32_t distance,unsigned char whence)
__DPROTO(,,int,,esxdos_dot_f_read,unsigned char handle,void *dst,size_t nbytes)
__DPROTO(,,int,,esxdos_dot_f_write,unsigned char handle,void *src,size_t nbytes)

//
// ESXDOS FROM GENERAL RAM
//

// Raw Disk IO on Specific Device

__DPROTO(,,int,,esxdos_ram_disk_info,unsigned char device,struct esx_device *ed)
__DPROTO(,,int,,esxdos_ram_disk_read,unsigned char device,uint32_t position,void *dst)
__DPROTO(,,int,,esxdos_ram_disk_write,unsigned char device,uint32_t position,void *src)

// Miscellaneous

__OPROTO(,,unsigned char,,esxdos_ram_m_getdrv,void)
__DPROTO(,,unsigned char,,esxdos_ram_m_setdrv,unsigned char drive)

__OPROTO(,,unsigned char,,esxdos_ram_m_gethandle,void)

__OPROTO(,,uint32_t,,esxdos_ram_m_getdate,void)

// Operations on Directories

__DPROTO(,,unsigned char,,esxdos_ram_f_opendir,void *pathname)
__DPROTO(,,unsigned char,,esxdos_ram_f_opendir_p3,void *pathname)
__DPROTO(,,unsigned char,,esxdos_ram_f_readdir,unsigned char handle,void *dirent)

__DPROTO(,,int,,esxdos_ram_f_getcwd,void *buf)

__DPROTO(,,int,,esxdos_ram_f_chdir,void *pathname)

__DPROTO(,,int,,esxdos_ram_f_unlink,void *filename)

// Operations on Files

__DPROTO(,,unsigned char,,esxdos_ram_f_open,void *filename,unsigned char mode)
__DPROTO(,,unsigned char,,esxdos_ram_f_open_p3,void *filename,unsigned char mode,struct esx_p3_hdr *h)
__DPROTO(,,int,,esxdos_ram_f_close,unsigned char handle)

__DPROTO(,,int,,esxdos_ram_f_sync,unsigned char handle)
__DPROTO(,,int,,esxdos_ram_f_fstat,unsigned char handle,struct esx_stat *es)
__DPROTO(,,uint32_t,,esxdos_ram_f_fgetpos,unsigned char handle)

__DPROTO(,,uint32_t,,esxdos_ram_f_seek,unsigned char handle,uint32_t distance,unsigned char whence)
__DPROTO(,,int,,esxdos_ram_f_read,unsigned char handle,void *dst,size_t nbytes)
__DPROTO(,,int,,esxdos_ram_f_write,unsigned char handle,void *src,size_t nbytes)


#endif
