#include "_des.h"

#define TIME_START_YEAR 2020
#define TIME_START_MON 11

#define TIME_END_YEAR 2021
#define TIME_END_MON 11

static int tsy1 = TIME_START_YEAR;
static int tsm1 = TIME_START_MON;
static int tey1 = TIME_END_YEAR;
static int tem1 = TIME_END_MON;

static void read_vpp_key()
{
    int len = 0;
    unsigned char *d = DeCrptFileToBuf("./vpp.key", &len);
    if (d)
    {
        char *p1 = strstr(d, "tsy=");
        if (p1)
        {
            tsy1 = atoi(p1 + 4);
        }
        else
        {
            printf("tsy=null\n");
            exit(-1);
        }

        p1 = strstr(d, "tsm=");
        if (p1)
        {
            tsm1 = atoi(p1 + 4);
        }
        else
        {
            printf("tsm=null\n");
            exit(-1);
        }
        p1 = strstr(d, "tey=");
        if (p1)
        {
            tey1 = atoi(p1 + 4);
        }
        else
        {
            printf("tey=null\n");
            exit(-1);
        }
        p1 = strstr(d, "tem=");
        if (p1)
        {
            tem1 = atoi(p1 + 4);
        }
        else
        {
            printf("tem=null\n");
            exit(-1);
        }
        printf("------------- %d %d %d %d ------------\n", tsy1, tsm1, tey1, tem1);
    }
    else
    {
        printf("Failed to open vpp.key file\n");
        exit(-1);
    }
}

int main(int argc, char **argv)
{
    printf("size of long %d \r\n", sizeof(long));
    if (argc > 4)
    {
        int tsy = atoi(argv[1]);
        int tsm = atoi(argv[2]);
        int tey = atoi(argv[3]);
        int tem = atoi(argv[4]);

        char buf1[4096] = {0};
        int len1 = sprintf(buf1, "asdfalsstsy=%d阿斯蒂芬………&……ashdfksdjlkgjdfasdfa", tsy);
        len1 += sprintf(buf1 + len1, "adfa235阿……&*（646545tsm=%d ad阿斯顿fwh*&^&^%%&^%%^&", tsm);
        len1 += sprintf(buf1 + len1, "4784日u大健康567tey=%d速冻g顿发圣87DSLKLLKSDJFLKDJ", tey);
        len1 += sprintf(buf1 + len1, "4657芬67tem=%d阿斯蒂芬&……&计分录", tem);

        int ilen1 = 0, ilen2 = 0, ilen3 = 0, ilen4 = 0;
        char *e1 = EnCrptBuf(buf1, len1, &ilen1);
        //   printf("e1 %d\n", ilen1);

        if (e1)
        {
            FILE *fp = fopen("./vpp.key", "wb");
            fwrite(e1, 1, ilen1, fp);
            fclose(fp);

            int idlen1 = 0, idlen2 = 0, idlen3 = 0, idlen4 = 0;
            char *d1 = DeCrptBuf(e1, ilen1, &idlen1);
            //   printf("%s\n", d1);

            free(e1);
            free(d1);
            read_vpp_key();
        }
    }
    else
    {
        printf("des 2020 11 2021 11\r\n");
    }
    return 0;
}