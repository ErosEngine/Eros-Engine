#ifndef EFILE_H
#define EFILE_H


enum FileFlags
{
	READ = 1,
	WRITE = 2,
	READ_WRITE = READ | WRITE,
	BINARY = 7,
	TEXT = 8,
	READ_BINARY = READ | BINARY,
	READ_TEXT = READ | TEXT,
	READ_WRITE_BINARY = READ_WRITE | BINARY,
	READ_WRITE_TEXT = READ_WRITE | TEXT	
};

class EFile
{
public:
	EFile();
	
	bool Open(const char *fileName, FileFlags flags);
	const char *GetStringData();
	void *GetRaw();
	
};

#endif // EFILE_H
