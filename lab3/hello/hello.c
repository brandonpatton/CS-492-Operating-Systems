#include <linux/module.h>
#include <linux/init.h>

//  Define the module metadata.
#define MODULE_NAME "hello"
MODULE_AUTHOR("Brandon Patton");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple kernel module to greet the installer");
MODULE_VERSION("0.1");

//  Define the name parameter.
static char *name = "bpatton";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

static int __init hello_init(void)
{
    pr_info("%s: module loaded at 0x%p\n", MODULE_NAME, hello_init);
    // TODO say hello to the named user
    printk(KERN_INFO "Hello User %s", name);
    return 0;
}

static void __exit hello_exit(void)
{
    // TODO say goodbye to the named user
    pr_info(KERN_INFO "Goodbye User %s", name);
    pr_info("%s: module unloaded from 0x%p\n", MODULE_NAME, hello_exit);
}

// TODO register the operations to be executed when the KM is loaded and unloaded
module_init(hello_init);
module_exit(hello_exit);
