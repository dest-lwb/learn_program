//编程范式 15 Programming Paradigms CS107 lecture 15
//航空售票模型解释多线程

int main()
{
	int numAgents = 10;
	int numTickets = 150;
	Semaphore lock = SemaphoreNew(-,2);
	/*
	for(int agent = 0; agent < numAgents; agent++){
		SellTickets(agent, numTickets, numAgents);
	}
	*/
	InitThreadPackege(false);
	
	for(int agent=0; agent <= numAgents; agent++){
		char name[32];
		sprintf("name, Agent %d Thread", agent);
		//ThreadNew(name, SellTickets, 2, agent, numTickets, numAgents);
		ThreadNew(name, SellTickets, 3, agent, &numTickets, lock);
	}
	RunAllThreads();
	
	return 0;
}

void SellTickets(int agentID, int numTicketsToSell)
{
	while(numTicketsToSell > 0){
		printf("Agent %d sells a ticket \n", agentID);
	}
	printf("Agent %d  All done! \n", agentID);
}

//
void SellTickets(int agentID, int *numTicketsp, Semahpore lock)
{
	while(true){
		SemaphoreWait(lock);
		if(*numTicketsp == 0) block;
		(*numTicketsp)--;
		printf("----");
		SemaphoreSignal(lock);
	}
	SemaphoreSignal(lock);
}
