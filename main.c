// #include "mgr/sys_mgr.h"
#include "include/_stdSFMSC.h"

int main(void)
{
    Manager mgr;

    manager_init(&mgr);

    manager_run(&mgr);

    manager_destroy(&mgr);

    return 0;
}
