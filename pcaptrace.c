#include <stdio.h>
#include <pcap.h>
#include "prettyhex.h"

int main(int argc, char *argv[])
{
char *filename = argv[1];
char *countstring  = argv[2];
unsigned char payload [23901];
struct pcap_file_header  fhdr ; 
struct pcap_pkthdr  phdr ; 
read ( 0, &fhdr, sizeof ( struct pcap_file_header )); 
printf ( "fheadr: mxgic 0x%x vers%d.%d, zone:%d, sigfigs: %d snaplen:%d linktyp:0x%x", 
		fhdr.magic, 
		fhdr.version_major, fhdr.version_minor,
		fhdr.thiszone,
		fhdr.sigfigs, fhdr.snaplen, fhdr.linktype); 
		
while ( 1 ) 
{
read ( 0, &phdr, sizeof ( struct pcap_pkthdr )); 
if ( read ( 0, &payload , phdr.caplen) <  1  ) return (0); 
printf ("\n\t packet: tvh: 0x%04x tvl:0x%04x caplen:0x%04x len:0x%04x ",
phdr.ts.tv_sec, phdr.ts.tv_usec, phdr.caplen, phdr.len);
printf ( "payload:______________________ \n%s",  prtyhx ( &payload, 10)); 
} /// end bigwhile_____________________________________________________
return(1);
}


