#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char boot_buf[512];
	int floppy desc, file_desc;

	file_desc = open("./boot", O_RDONLY); // Open boot in read-only
	read(file_desc, boot_buf, 510); // Read 510 bytes/until file end
	close(file_desc) // Close file
	
	/* BIOS requires 510 & 511 to be 0x55 and 0xaa respectively */
	boot_buf[510] = 0x55; 
	boot_buf[511] = 0xaa;

	floppy_desc = open("/dev/fd0", O_RDWR); // Open floppy disk device
	lseek(floppy_desc, 0, SEEK_CUR); // Start from the beginning
	write(floppy_desc, boot_buf, 512); // Write 512 bytes to the floppy
	close(floppy_desc); // Close file
}
