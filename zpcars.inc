#define isnull(%0) ((%0[(%0[0])=='\1'])=='\0')
#include <YSI_Data\y_iterate>
#include <YSI_Coding\y_hooks>

//SETTINGS DATABASE
#define ConnectToDatabaseZPC true

#if ConnectToDatabaseZPC true
new MySQL:zpc_SQL_ID;

#define DB_HOST         "localhost"
#define DB_USERNAME     "zyzu"
#define DB_PASSWORD     "123"
#define DB_DATABASE     "samp_database"

#endif
//

//define
#define MAX_PRIV_VEH_PLAYER     (100)

//ITERATORS
new Iterator:I_PPRIVCARS[MAX_PLAYERS]<MAX_PRIV_VEH_PLAYER>;

//ARRAYS / ENUMS
enum E_PLAYERPRIVVEHICE
{
    zpc_vid,
    zpc_vname[32]
};
new PlayerPrivVeh[MAX_PRIV_VEH_PLAYER][E_PLAYERPRIVVEHICE];

//CALLBACKS
hook OnScriptInit()
{
	Iter_Init(I_PPRIVCARS);
	return 1;
}

stock AddPrivCarToPlayer(playerid, vehicleid)
{

    return 1;
}

stock RemovePrivCarToPlayer(playerid, vehicleuid)
{

    return 1;
}

stock SellPrivCarPlayerToPlayer(playerid, targerid, vehicleuid)
{

    return 1;
}

#if ConnectToDatabaseZPC true

stock zpc_condb()
{
	mysql_log();

	new MySQLOpt: option_id = mysql_init_options();
	mysql_set_option(option_id, AUTO_RECONNECT, true);
	//zpc_SQL_ID = mysql_connect(DB_HOST, DB_USERNAME, DB_PASSWORD, DB_DATABASE, option_id);
	
	if(zpc_SQL_ID == MYSQL_INVALID_HANDLE || mysql_errno(zpc_SQL_ID) != 0)
	{
		print("[ZPC Error] MySQL was unable to connect to the database!");
		return 0;
	}
	print("[ZPC Init] MySQL has established a connection to the database.");
	return 1;
}

#endif