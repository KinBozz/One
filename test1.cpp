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

	// λ���Ƿ񳬳�
	static bool isBeyond = false;
	// ÿһ��Բ��X��Y����ֵ���뾶���ӵ���С����
	static int step = 10;
	
	printf("\t������Բ�ĸ�����");
	
	scanf("%d", &rNUM);
	// �����е�Բ��λ�����
	while (n < rNUM)
	{
		// ����Ҫ����һ���ظ�ʹ�õı���
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
			// ��¼���θ����
			rdsRecord[n] = nMaxRds;
			positionXRecord[n] = nBestPositionX;
			positionYRecord[n] = nBestPositionY;
		}
		else
		{
			// ����� n ��Բ�����뾶 �� λ��
			for ( nPositionX = 0; nPositionX <= A; nPositionX+=step)
			{
				for ( nPositionY = 0; nPositionY <= A; nPositionY+=step)
				{
					isBeyond = false;
					nRds = 0;
					// ������İ뾶
					while(nRds <= borderRds && !isBeyond)
					{
						// �ж�Բ�ĺͱ߽�ľ��룬Բ���ܳ��������οռ�
						if ((nRds > nPositionX) || (nRds > nPositionY) || (A < nPositionX + nRds) || (A < nPositionY + nRds))
						{
							// printf("%d, (%d, %d), �����˷�Χ\n", n, nPositionX, nPositionY);
							isBeyond = true;
							break;
						}
						// �ж�Բ�������е�Բ�ļ�ľ���
						// Բ�Ĳ����������е�Բ��, ��ǰ��ԲҲ���������е�Բ�ཻ
						for (int i = 0; i < n; ++i)
						{
							// ������ѻ�����Բ�ཻ���߱��ѻ�����Բ����
							if ((nRds + rdsRecord[i]) * (nRds + rdsRecord[i]) >
									 (nPositionX - positionXRecord[i]) * (nPositionX - positionXRecord[i]) + (nPositionY - positionYRecord[i]) * (nPositionY - positionYRecord[i]))
							{
								// printf("�����˷�Χ, nRds: %d, (%d, %d), rdsRecord[i]: %d, (%d, %d).\n", nRds, nPositionX, nPositionY, rdsRecord[i], positionXRecord[i], positionYRecord[i]);
								isBeyond = true;
								break;
							}
						}
						// ���û�г�����������û����ԭ�е�Բ�ص�, �Ұ뾶����
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
		// ��¼���θ����
		rdsRecord[n] = nMaxRds;
		positionXRecord[n] = nBestPositionX;
		positionYRecord[n] = nBestPositionY;
		// �Ե�ǰ�ҵ������Բ�İ뾶����Ϊ��һ��Բ���ܳ��ֵ����뾶
		borderRds = nMaxRds;

		step = nMaxRds/1000;
		if (step < 5)
		{
			step = 5;
		}

		++n;
	}
	printf("* * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("*\t���Ϊ:        \n");
	for (int i = 0; i < rNUM; i++)
	{
		printf("*\t��%d��Բ�İ뾶�ǣ�%d, Բ���ǣ�(%d, %d).  \n", i, rdsRecord[i], positionXRecord[i], positionYRecord[i]);
	}
	printf("* * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

	return 0;
}




