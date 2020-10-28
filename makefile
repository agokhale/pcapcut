all:
	cc -c prettyhex.c
	cc -g -o pcapcut  pcapcut.c
	cc -g -o pcaptrace  prettyhex.o pcaptrace.c
test: all
	cat destiny.ssh.pcap | ./pcapcut asd 5 10 | tcpdump -r - 
testtrace:
	cat destiny.ssh.pcap | ./pcaptrace
install: 	all
	cp  pcapcut /usr/local/bin
clean:
	rm  -f a.out  pcapcut
