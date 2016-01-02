# libhash

## Installation

    make && make test

## Simple use case

    #include <libhash.h>

    /*
    ** Create a function to delete your table content.
    */
    void    delete(void *e)
    {
        (void)e;
    }

    int     main(void)
    {
        t_hashtable *h;

        ht_create(&delete);
        ht_set("randomKey1", "Content");
        printf("%s\n", ht_get(h, "randomKey1"));
        ht_delete(&h);
        return (0);
    }
