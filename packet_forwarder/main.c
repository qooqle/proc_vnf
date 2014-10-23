#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>

#include "commn.h"

struct mqd_t * init_mq(char *mq_name) {
	mqd_t mq;
	struct mq_attr attr;
	char buf[BUFSIZE];

	attr.mq_flags = 0;
	attr.mq_maxmsg = MQ_MSG;
	attr.mq_maxsize = MQ_MSG_SIZE;
	attr.mq_curmsgs = 0;

	return (&mq);
}

int mk_tx_mq(struct mqd_t *mq) {
	mq = mq_open(mq_name, O_CREAT | O_RDONLY, 0644, &attr);
	CHECK((mqd_t) -1 != mq);
}

int mk_rx_mq(struct mqd_t *mq) {
	mq = mq_open(mq_name, O_CREAT | O_WRONLY, 0644, &attr);
	CHECK((mqd_t) -1 != mq);
}

int recv_from_nic() {

}

int send_to_nic() {

}

int lookup_next() {

}

int main(int argc, char **argv) {

	for(int i =0, i < vnfs, i++){
		mk_tx_mq();
		mk_rx_mq();
	}

	while(1){
		if (recv_from_nic()) {
			
		}	
	}
}
