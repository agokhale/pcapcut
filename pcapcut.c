#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
char *filename = argv[1];
char *countstring  = argv[2];
unsigned int  gindex_start = 666; 
unsigned int  gindex_stop = 666; 
unsigned int  gindex = 0; 
unsigned int  gcursor = 666; 
unsigned char payload [23901];
struct pcap_file_header  fhdr ; 
struct pcap_pkthdr  phdr ; 
long fpos = -2; 

sscanf (argv[2], "%d", &gindex_start); 
sscanf (argv[3], "%d", &gindex_stop); 
read ( 0, &fhdr, sizeof ( struct pcap_file_header )); 
write  ( 1, &fhdr, sizeof ( struct pcap_file_header )); 

printf ( "fheadr: mxgic 0x%x vers%d.%d, zone:%d, sigfigs: %d snaplen:%d linktyp:0x%x", 
		fhdr.magic, 
		fhdr.version_major, fhdr.version_minor,
		fhdr.thiszone,
		fhdr.sigfigs, fhdr.snaplen, fhdr.linktype); 
		
while ( 1 ) 
	{
	read ( 0, &phdr, sizeof ( struct pcap_pkthdr )); 
	read ( 0, &payload , phdr.caplen); 
	if (( gindex >= gindex_start)  && (gindex <= gindex_stop ))
		{
		write ( 1, &phdr, sizeof (phdr)  ); 
		write ( 1, &payload, phdr.caplen  ); 
		}
	if ( gindex > gindex_stop)
		return (0); 
	
	gindex ++;
	
	}

return(0);
}


