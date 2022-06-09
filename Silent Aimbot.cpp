void *MyPlayer;

bool (*get_isMine)(void *Player);

void *(*get_transform)(void *instance);

bool PlayerAlive(void* player)
{
    return PlayerScript.PlayerAlive(player, true);
}


void silentAimbot(void * instance)
{
    if(instance != NULL)
    {
        bool (*Fire)(void *, int, float, Vector3, Vector3, bool, double);
        Fire = (bool (*)(void *, int, float, Vector3, Vector3, bool, double))getRealOffset(0x123CA58);

        if(get_isMine(instance)) {
            MyPlayer = instance;
        }

        auto players = PhotonNetwork_get_OtherPlayers();

        for(int i = 0; i < players->getLength(); i++)
        {
            auto player = players->getPointer()[i];

            Vector3 OtherPos = get_position(get_transform(player));

            if(player == NULL || player == 0x0)
                continue;

            if(!PlayerUtils.IsPlayerOnTeam(MyPlayer, player) && PlayerAlive(player))
            {
                Fire(MyPlayer, 1, 100.0f, GetPlayerLocation(player), Vector3::Forward(), false, 0.0);
            }
        }

    }
}
