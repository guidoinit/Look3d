#pragma once

class baseframe
{
private:
	int _fstart;
	int _fend;
public:
	baseframe(int fstart,int fend);
	baseframe(void);
	~baseframe(void);
//	virtual void Serialize(CArchive &ar);
	
	int getstart();
	int getend();

	void setstart(int);
	void setend(int);

	baseframe(const baseframe& bf)
	{
		_fstart=bf._fstart;
		_fend=bf._fend;

	}

	baseframe operator=(baseframe& bf)
	{
		_fstart=bf._fstart;
		_fend=bf._fend;

		return *this;
	}
};

