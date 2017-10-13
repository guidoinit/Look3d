//    This file is part of Look3D program.

//    Look3D is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    Look3D is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>
//	
//

#include "stdafx.h"

#include "toolbitmap.h"

#include "enemy.h"




CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{

}


CEnemy::CEnemy(int liv)
{
/*	int x;
	int cx=10;
	int cy=0;


	m_livello=liv;
	switch(liv)
	{
	case 1:
		m_anim=true;
		m_nume=5;
		m_mydeath=20;
		m_kill= new CToolBitmap(IDB_BIT_ENEMYD);
		m_fire = new CToolBitmap(IDB_BIT_FIREE);

		m_bfire=false;
		for (x=0; x < m_nume ; x++)
		{
			pene[x].x=cx;
			pene[x].y=cy;
			isd[x]=10;
			
			m_bit[x] = new CToolBitmap(IDB_BIT_ENEMY1);
			cx+=32;
			if(cx>160)
			{
				cx=10;
				cy=32;
			}

		}
		break;

		

	}*/
	SetLevel(liv);

}
void CEnemy::DrawEnemy(CDC * pdc)
{


	static int countf=0;
	int x;

	int wfire;
	::srand(time(NULL));

	wfire=rand() % m_nume +1;


	if(isd[wfire] > 0 && !m_bfire)
	{
		m_bfire=true;
		
		m_pfire.x=pene[wfire].x + 8;
		m_pfire.y=pene[wfire].y + 32;

	}

	countf++;
	
//	if (m_anim)
//		doanim(1,pdc);
	for (x=0; x < m_nume ; x++)
		if (isd[x] > 0 && m_bit[x]!=NULL)
			m_bit[x]->DrawBitmap(pdc,pene[x].x,pene[x].y);
		else if (isd[x]==0)
		{
				m_kill->DrawBitmap(pdc,pene[x].x,pene[x].y);
				isd[x]=-1;
		}

	if( countf>10 && m_bfire )
	{
		
		
		
		Fire(wfire,pdc);

		if (countf>20)
		
		{
			
			m_bfire=false;
		
			countf=0;
		
		}
		
	}
	


}

bool CEnemy::IsDeath(CPoint point,CPoint point2)
{
	bool isd=false;









	return true;

}

bool CEnemy::IsDeath(CRect rect)
{
	int x;
	int top=rect.top;
	int left=rect.left;
	int left2 = left+rect.Width();

	CPoint pointd;

	


	for (x = 0 ; x < m_nume ; x ++)
	{
		//isd[x]=false;
		pointd.x=pene[x].x + 16;
		pointd.y=pene[x].y + 16;
	//	if ( top > ( pene[x].y + 32 ) && left > pene[x].y && left2 < pene[x].y + 32 )
		if (pointd.x > rect.left && pointd.x < rect.right && pointd.y>rect.top && pointd.y< rect.bottom)
			if (isd[x] > 0)
				isd[x]--;
			
	}

	return true;


}
void CEnemy::doanim(int nanim,CDC *pdc)
{
	int x,y,cx,cy;


	

	for (x=0; x < 20 ; x++)
	{
		if(x<10)
			pene[x].y=0;
		else
			pene[x].y=32;
		
		pene[x].x=0;
	}
	


	switch (nanim)
	{
	case 1:
		cx=10;
		for (x=0 ; x < 20 ; x ++)
		{
			pene[x].x=cx;
			
			cx+=32;
			if (x>10)
				cx=10;
		}




		break;
	}

	for (x=0; x < 20 ; x++)
		if (!isd[x])
			m_bit[x]->DrawBitmap(pdc,pene[x].x,pene[x].y);
	
	cx=10;
	cy=0;

	for (x=0; x < 20 ; x++)
	{
		pene[x].x=cx;
		pene[x].y=cy;
		isd[x]=false;
		//m_bit[x] = new CToolBitmap(IDB_BIT_ENEMY1);
		cx+=32;
		if(cx>320)
		{
			cx=10;
			cy=32;
		}

	}

}

bool CEnemy::win()
{
	int x;
	int countw=0;

	for (x=0; x < m_nume; x++)
		if ( isd[x]<=0 )
			countw++;

	return( countw == m_nume );
}

void CEnemy::Fire(int ne,CDC *pdc)
{
	CPoint pointd;

	
	m_fire->DrawBitmap(pdc,m_pfire.x,m_pfire.y);

	if ( m_pfire.y > 110 )
		m_bfire=false;
		
	m_pfire.y+=10;


}

void CEnemy::SetLevel(int liv)
{
	int x;
	int cx=50;
	int cy=0;

	m_livello=liv;
	switch(liv)
	{
	case 1:
		m_anim=true;
		m_nume=5;
		m_mydeath=20;
		m_kill= new CToolBitmap(IDB_BIT_ENEMYD);
		m_fire = new CToolBitmap(IDB_BIT_FIREE);

		m_bfire=false;
		for (x=0; x < m_nume ; x++)
		{
			pene[x].x=cx;
			pene[x].y=cy;
			isd[x]=10;
			
			m_bit[x] = new CToolBitmap(IDB_BIT_ENEMY1);
			cx+=32;
			if(cx>190)
			{
				cx=50;
				cy=32;
			}

		}
		break;
	case 2:
		free(m_kill);
		free(m_fire);

		m_nume=5;
		m_bfire=false;
		for (x=0; x < m_nume ; x++)
		{
			isd[x]=10;
			pene[x].x=cx;
			pene[x].y=cy;
			isd[x]=10;
			free(m_bit[x]);
			m_bit[x] = new CToolBitmap(IDB_BIT_ENEMY2);
			cx+=32;
			if(cx>160)
			{
				cx=50;
				cy=32;
			}

		}
		break;

		

	}

}
