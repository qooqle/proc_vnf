#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>

#include "commn.h"

#define MAX_VNF 10;

void mk_mq(mqd_t *mqp, char *mq_name) {
	struct mq_attr attr;
	char buf[BUFSIZE];

	attr.mq_flags = 0;
	attr.mq_maxmsg = MQ_MSG;
	attr.mq_maxsize = MQ_MSG_SIZE;
	attr.mq_curmsgs = 0;

	*mq = mq_open(mq_name, O_CREAT | O_RDWR | O_NONBLOCK, 0644, &attr);
	CHECK((mqd_t) -1 != *mq);
}

int recv_from_nic(char *pkt_buf_ptr) {
	/* netmap TX injection*/

}

int send_to_nic(char *pkt_buf_ptr) {
	/* netmap TX injection*/

}

int main(int argc, char **argv) {
	mdt_t mq[MAX_VNF];
	char mq_name[MAX_VNF][7];
	char *pkt_buf_ptr;

	/* create message queues for individual VNF */
	for(i=0; i < MAX_VNF; i++) {
		mq_name[i] = atoi(i);
		mk_mq(&mq[i], mq_name[i]);
	}

	while(1){
		n = mq_receive(mq, pkt_buf_ptr, MQ_MSG_SIZE, NULL);
		CHECK(n >= 0);

	        n = mq_send(mq, pkt_buf_ptr, MQ_MSG_SIZE, 0);
                CHECK(n >= 0);


		send_to_nic(pkt_buf_ptr);
	}

	CHECK((mqd_t)-1 != mq_close(mq));
	CHECK((mqd_t)-1 != mq_unlink(mq_name));

	return 0;
}
