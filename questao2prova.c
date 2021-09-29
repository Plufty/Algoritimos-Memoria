int nru(int8_t** page_table, int num_pages, int prev_page,
        int fifo_frm, int num_frames, int clock)
{
    int classe0, classe1, classe2, classe3;
    int completo = 0;

    for (classe0 = 0; classe0 < num_pages; classe0++)
    {    
        if(page_table[classe0][BIT_R] == 0 && page_table[classe0][BIT_M] == 0)//classe 0
        {
            return classe0;
            completo = 1;
            break;
        }
    }
    if (completo == 0)
    {
        for (classe1 = 0; classe1 < num_pages; classe1++)
        {
            if(page_table[classe0][BIT_R] == 0 && page_table[classe0][BIT_M] == 1)//classe 1
            {
                return classe1;
                completo = 1;
                break;
            }
        }
        if (completo == 0)
        {
            for (classe2 = 0; classe2 < num_pages; classe2++)
            {
                if(page_table[classe0][BIT_R] == 1 && page_table[classe0][BIT_M] == 0)//classe 2
                {
                    return classe2;
                    completo = 1;
                    break;
                }
            }
            if (completo == 0)
            {
                for (classe3 = 0; classe3 < num_pages; classe3++)
                {
                    if(page_table[classe0][BIT_R] == 1 && page_table[classe0][BIT_M] == 1)//classe 3
                    {
                        return classe3;
                        completo = 1;
                        break;
                    }
                }
            }    
        }    
    }
}