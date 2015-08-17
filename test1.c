#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fp;
	char returnData[64];
	char *returnData2;
	char *returnData3;
	int x = 0 , y = 0;
	fp = popen("/sbin/ifconfig eth0", "r");
	while (fgets(returnData, 64, fp) != NULL)
	{
		returnData2 = strtok(returnData, "\n");
		while (returnData2 != NULL)
		{
			if(x == 1)
			{
				returnData3 = strtok(returnData2, " ");
				while (returnData3 != NULL)
				{
					if(y == 1)
					{
		 				printf("IP %s\n",returnData3);
					}
					returnData3 = strtok(NULL, "  ");
					y++;
				}
			}
			returnData2 = strtok(NULL, "\n");
			x++;
		}
	}
	pclose(fp);
}
