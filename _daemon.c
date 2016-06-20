#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>
#include <linux/limits.h>



#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>
#include <linux/limits.h>

#define NR_OPEN 1024

int _daemon(int nochdir, int noclose) {
    pid_t pid;
    int i;

    /* fork islemi */
    pid = fork ( );
    if (pid == -1)
        return -1;
    else if (pid != 0) {
        exit (EXIT_SUCCESS);
    }

    if (setsid() == -1)
        return -1;

      if (!nochdir) { /*root*/
        if (chdir("/") == -1)
            return -1;
    }

    if (!noclose) { /*betim dolduruluyor*/
        for (i = 0; i < NR_OPEN; i++)
            close (i);
        open("/dev/null", O_RDWR);
        dup(0);
        dup(0);
    }

    return 0;
}
