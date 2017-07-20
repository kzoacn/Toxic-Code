#include <bits/stdc++.h>
using namespace std;
int n, Gx, Gy;
bool gg[15][15];
int p[15][15];
char buf[5];
int GGx, GGy;
bool Judge()
{
	if(Gy != GGy)
	{
		return 0;
	}
	for(int i = Gx + 1; i < GGx; i++)
	{
		if(p[i][Gy])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	while(scanf("%d%d%d", &n, &Gx, &Gy) && (n || Gx || Gy))
	{
		memset(gg, 0, sizeof(gg));
		memset(p, 0, sizeof(p));
		for(int x, y, i = 1; i <= n; i++)
		{
			scanf("%s%d%d", buf, &x, &y);
			if(buf[0] == 'G')
			{
				p[x][y] = 1;
				GGx = x;
				GGy = y;
			}
			else if(buf[0] == 'R')
			{
				p[x][y] = 2;
			}
			else if(buf[0] == 'H')
			{
				p[x][y] = 3;
			}
			else
			{
				p[x][y] = 4;
			}
		}
		if(Judge())
		{
			printf("NO\n");
			continue;
		}
		for(int i = 1; i <= 10; i++)
		{
			for(int j = 1; j <= 9; j++)
			{
				if(p[i][j] == 1)
				{
					for(int k = i - 1; k; k--)
					{
						gg[k][j] = 1;
						if(p[k][j])
						{
							break;
						}
					}
				}
				else if(p[i][j] == 2)
				{
					for(int k = i + 1; k <= 10; k++)
					{
						gg[k][j] = 1;
						if(p[k][j])
						{
							break;
						}
					}
					for(int k = i - 1; k; k--)
					{
						gg[k][j] = 1;
						if(p[k][j])
						{
							break;
						}
					}
					for(int k = j + 1; k <= 9; k++)
					{
						gg[i][k] = 1;
						if(p[i][k])
						{
							break;
						}
					}
					for(int k = j - 1; k; k--)
					{
						gg[i][k] = 1;
						if(p[i][k])
						{
							break;
						}
					}
					
				}
				else if(p[i][j] == 3)
				{
					if(i - 2 > 0 && p[i - 1][j] == 0)
					{
						gg[i - 2][j - 1] = 1;
						gg[i - 2][j + 1] = 1;
					}
					if(i + 2 <= 10 && p[i + 1][j] == 0)
					{
						gg[i + 2][j - 1] = 1;
						gg[i + 2][j + 1] = 1;
					}
					if(j - 2 > 0 && p[i][j - 1] == 0)
					{
						gg[i + 1][j - 2] = 1;
						gg[i - 1][j - 2] = 1;
					}
					if(j + 2 <= 9 && p[i][j + 1] == 0)
					{
						gg[i + 1][j + 2] = 1;
						gg[i - 1][j + 2] = 1;
					}
				}
				else if(p[i][j] == 4)
				{
					for(int k = i + 1; k <= 10; k++)
					{
						if(p[k][j])
						{
							for(k++; k <= 10; k++)
							{
								gg[k][j] = 1;
								if(p[k][j])
								{
									break;
								}
							}
							break;
						}
					}
					for(int k = i - 1; k; k--)
					{
						if(p[k][j])
						{
							for(k--; k >= 1; k--)
							{
								gg[k][j] = 1;
								if(p[k][j])
								{
									break;
								}
							}
							break;
						}
					}
					for(int k = j + 1; k <= 9; k++)
					{
						if(p[i][k])
						{
							for(k++; k <= 9; k++)
							{
								gg[i][k] = 1;
								if(p[i][k])
								{
									break;
								}
							}
							break;
						}
					}
					for(int k = j - 1; k; k--)
					{
						if(p[i][k])
						{
							for(k--; k >= 1; k--)
							{
								gg[i][k] = 1;
								if(p[i][k])
								{
									break;
								}
							}
							break;
						}
					}
				}
			}
		}
		if(!gg[Gx][Gy])
		{
			printf("NO\n");
			continue;
		}
		if(Gx - 1 >= 1 && !gg[Gx - 1][Gy])
		{
			printf("NO\n");
			continue;
		}
		if(Gx + 1 <= 3 && !gg[Gx + 1][Gy])
		{
			printf("NO\n");
			continue;
		}
		if(Gy - 1 >= 4 && !gg[Gx][Gy - 1])
		{
			printf("NO\n");
			continue;
		}
		if(Gy + 1 <= 6 && !gg[Gx][Gy + 1])
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}
