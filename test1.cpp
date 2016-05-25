#include <stdio.h>



int main(int argc, char const *argv[])
{
	static const int A = 10000;
	 int rNUM ;
	static int n = 0;

	static int rdsRecord[2000];
	static int positionXRecord[2000];
	static int positionYRecord[2000];

	static int nRds = 1;
	static int nPositionX = 0;
	static int nPositionY = 0;

	static int nMaxRds = 0;
	static int nBestPositionX = 0;
	static int nBestPositionY = 0;

	static int borderX = A;
	static int borderY = A;
	static int borderRds = A / 2;

	// 位置是否超出
	static bool isBeyond = false;
	// 每一次圆的X、Y坐标值、半径增加的最小步长
	static int step = 10;
	
	printf("\t请输入圆的个数：");
	
	scanf("%d", &rNUM);
	// 把所有的圆的位置求出
	while (n < rNUM)
	{
		// 重置要在下一次重复使用的变量
		nPositionX = 0;
		nPositionY = 0;
		nMaxRds = 0;
		nBestPositionX = 0;
		nBestPositionY = 0;

		if (n == 0)
		{
			nMaxRds = A/2;
			nBestPositionX = A/2;
			nBestPositionY = A/2;
			// 记录本次个结果
			rdsRecord[n] = nMaxRds;
			positionXRecord[n] = nBestPositionX;
			positionYRecord[n] = nBestPositionY;
		}
		else
		{
			// 求出第 n 个圆的最大半径 和 位置
			for ( nPositionX = 0; nPositionX <= A; nPositionX+=step)
			{
				for ( nPositionY = 0; nPositionY <= A; nPositionY+=step)
				{
					isBeyond = false;
					nRds = 0;
					// 求出最大的半径
					while(nRds <= borderRds && !isBeyond)
					{
						// 判断圆心和边界的距离，圆不能超出正方形空间
						if ((nRds > nPositionX) || (nRds > nPositionY) || (A < nPositionX + nRds) || (A < nPositionY + nRds))
						{
							// printf("%d, (%d, %d), 超出了范围\n", n, nPositionX, nPositionY);
							isBeyond = true;
							break;
						}
						// 判断圆心与已有的圆心间的距离
						// 圆心不能落在已有的圆中, 当前的圆也不能与已有的圆相交
						for (int i = 0; i < n; ++i)
						{
							// 如果与已画出的圆相交或者被已画出的圆包含
							if ((nRds + rdsRecord[i]) * (nRds + rdsRecord[i]) >
									 (nPositionX - positionXRecord[i]) * (nPositionX - positionXRecord[i]) + (nPositionY - positionYRecord[i]) * (nPositionY - positionYRecord[i]))
							{
								// printf("超出了范围, nRds: %d, (%d, %d), rdsRecord[i]: %d, (%d, %d).\n", nRds, nPositionX, nPositionY, rdsRecord[i], positionXRecord[i], positionYRecord[i]);
								isBeyond = true;
								break;
							}
						}
						// 如果没有超出正方形且没有与原有的圆重叠, 且半径更大
						if (nRds > nMaxRds)
						{
							nMaxRds = nRds;
							nBestPositionX = nPositionX;
							nBestPositionY = nPositionY;
						}
						nRds+=step;
					}
				}
			}
		}
		// 记录本次个结果
		rdsRecord[n] = nMaxRds;
		positionXRecord[n] = nBestPositionX;
		positionYRecord[n] = nBestPositionY;
		// 以当前找到的最大圆的半径，设为下一个圆可能出现的最大半径
		borderRds = nMaxRds;

		step = nMaxRds/1000;
		if (step < 5)
		{
			step = 5;
		}

		++n;
	}
	printf("* * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("*\t结果为:        \n");
	for (int i = 0; i < rNUM; i++)
	{
		printf("*\t第%d个圆的半径是：%d, 圆心是：(%d, %d).  \n", i, rdsRecord[i], positionXRecord[i], positionYRecord[i]);
	}
	printf("* * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

	return 0;
}




