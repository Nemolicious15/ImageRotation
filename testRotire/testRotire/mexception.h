#ifndef MEXCEPTION_H_INCLUDED
#define MEXCEPTION_H_INCLUDED

class MException{

private:
	const char* message;
public:
	MException(const char* m) : message(m){
	}
	const char* getMessage(){
		return message;
	}
};

#endif // MEXCEPTION_H_INCLUDED
