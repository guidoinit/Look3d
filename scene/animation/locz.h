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
#pragma once
#include "baseframe.h"

class locz:public baseframe
{
private:
	float _z;
public:
	locz(int fstart, int fend, float z);
	locz(void);
	~locz(void);
//	virtual void Serialize(CArchive &ar);

	float get();
	void set(float);

	locz(const locz& loc)
	{
		_z=loc._z;
		baseframe((baseframe&)loc);
	}
	locz operator=(locz& loc)
	{
		_z=loc._z;
		baseframe((baseframe&)loc);


		return *this;
	}
};

