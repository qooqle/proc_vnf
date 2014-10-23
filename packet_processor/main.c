#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>

#include "commn.h"

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

int proc_packet(char *pkt_buf_ptr) {

/*
	static de ok NAT process
*/

	return 1;
}

int main(int argc, char **argv) {
	mdt_t mq;
	char mq_name[7];
	char *pkt_buf_ptr;

	memset(mq_name, 0, sizeof(mq_name));
	mq_name = argv[1];

	mk_mq(&mq, mq_name);

	while(1){
		n = mq_receive(mq, pkt_buf_ptr, MQ_MSG_SIZE, NULL);
		CHECK(n >= 0);

		n = proc_packet(pkt_buf_ptr);
		CHECK(n >= 0);

	        n = mq_send(mq, pkt_buf_ptr, MQ_MSG_SIZE, 0));
                CHECK(n >= 0);
	}

	CHECK((mqd_t)-1 != mq_close(mq));
	CHECK((mqd_t)-1 != mq_unlink(mq_name));

	return 0;
}
