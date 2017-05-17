#pragma once
#include "Condition.h"
#include "Attribute.h"
//#include "File.h"
#include "BufferManager.h"
#include <string>
#include <vector>

using namespace std;

class RecordManager
{
public:
	RecordManager();
	~RecordManager();
	BufferManager bufferManager;
	//Table operation
	bool createTable(string tableName);
	bool dropTable(string tableName);
	//Index operation
	bool createIndex(string indexName);
	bool dropIndex(string indexName);
	//Record operation
	int insertRecord(string tableName, char* recordContent, int size); //Return the block offset
	int findRecord(string tableName, vector<Attribute>* attriList, vector<Condition> *conditionList);
	void showRecord(string tableName, vector<Attribute>* attriList, vector<Condition> *conditionList);
	bool deleteRecord(string tableName, vector<Attribute>* attriList, vector<Condition> *conditionList);
private:
	size_t getTypeSize(int type);
	int findRecordInBlock(string tableName, vector<Attribute>* attriList, vector<Condition>* conditionList, Block * block);
	void showRecordInBlock(string tableName, vector<Attribute>* attriList, vector<Condition> *conditionList, Block* block);
	void showSingleRecord(char* content, int size, vector<Attribute>* attriList);
	bool deleteRecordInBlock(string tableName, vector<Attribute>* attriList, vector<Condition> *conditionList, Block* block);
	bool fitCondition(char* recordContent, int size, vector<Attribute>* attriList, vector<Condition>* conditionList = NULL);
	bool compare(char* element, int size, Condition* condition);
};

