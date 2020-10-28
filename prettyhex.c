#ifndef u8 
#define u8  unsigned char  
#define u32  unsigned int
#endif 
char prtyhx_cbuf [2028];
const char *prty_hexabet  =  "0123456789abcdef";
char * prtyhx( const u8  * ibuf, u32 ilen ) //trades thread unsafe fr leaky and slo
{
u8 msb, lsb ; 
u32 i=0; 
u8 * obufp = prtyhx_cbuf; 
ilen = (ilen > 513) ? 512: ilen; 
for  ( i=0 ; i  < ilen ; ) 
	{
	*obufp++ =  prty_hexabet[ ibuf[i] >>    4 ];
	*obufp++ =  prty_hexabet[ ibuf[i] & 0x0f  ];
	i++;
	if (i%4 == 0) *obufp++ = (i%32 == 0 )? 10: ' ' ; 
	}
*obufp =  0; 
return (prtyhx_cbuf);
} 
