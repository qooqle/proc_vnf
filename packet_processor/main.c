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

int mk_tx_mq(char *mq_name) {
	mqd_t *mq;

	mq = init_mq(mq_name);

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

	char tx_mq_name[7];
	char rx_mq_name[7];

	memset(mq_name, 0, sizeof(mq_name));
	mq_name = argv[1];

	mk_tx_mq();
	mk_rx_mq();

	while(1){
		n = mq_receive(mq, buffer, MQ_MSG_SIZE, NULL);
		CHECK(n >= 0);

		n = proc_packet(buffer)
		CHECK(n >= 0);

	        n = mq_send(mq, buffer, MQ_MSG_SIZE, 0));
                CHECK(n >= 0);
	}
}
