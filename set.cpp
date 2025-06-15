#include "stdafx.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::Sql;
using namespace System::Data::SqlTypes;
using namespace Microsoft::SqlServer::Server;

// In order to debug your Aggregate, add the following to your debug.sql file:
//
// if object_id ('test_table') is not null
//	DROP TABLE test_table

// CREATE TABLE test_table ( Column1 nvarchar(max))
// INSERT INTO test_table values (N'a')

// select dbo.Aggregate1(Column1) from test_table

[Serializable]
[Microsoft::SqlServer::Server::SqlUserDefinedAggregate(Format::Native)]
public value struct Aggregate1 
{    
public:
	void Init()
	{
		// TODO: Put your code here
	}
	
	void Accumulate(SqlTypes::SqlString Value)
	{
		// TODO: Put your code here
	}

	void Merge(Aggregate1 Group)
	{
		// TODO: Put your code here
	}

	SqlTypes::SqlString Terminate()
	{
		SqlTypes::SqlString Value(L"");
		return Value;
	}

private:
    // This is a place-holder member
    int var1;
};
