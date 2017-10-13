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

#ifndef _ENEMY_
#define _ENEMY_




class CEnemy : public CObject
{
	CEnemy();
	~CEnemy();

	

public:
	void SetLevel(int liv);
	void Fire(int ne,CDC * pdc);

	int m_livello;
	CEnemy(int livello);

	bool win();
	void DrawEnemy(CDC * pdc);
	bool IsDeath(CRect rect);
	bool IsDeath(CPoint point,CPoint point2);

private:
	bool m_bfire;

	int m_mydeath;
	int m_nume;
	CPoint pene[20],m_pfire;

	CToolBitmap * m_bit[20];
	CToolBitmap * m_kill;
	CToolBitmap * m_fire;
	int isd[20];
	bool m_anim;

	void doanim(int nanim,CDC * pdc);





};









#endif