#pragma once

#ifndef SCANNER_H_
#define SCANNER_H_

template <class T>
class Scanner
{
public:
	virtual void scan(T& product) = 0;
	// virtual ~Scanner() {}
};

#endif /*SCANNER_H_*/