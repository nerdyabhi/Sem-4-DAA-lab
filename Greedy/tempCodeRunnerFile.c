    relaxation process begins
        for(int k=0; k<n; k++)
        {
            if(dist[k]!=99 && check[k] == false && k!=sv)
            {
                if(dist[k] > dist[mini] + cost[min_index][min_index] )
                {
                    dist[k] = dist[mini] + cost[min_index][min_index];
                }
            }

        }