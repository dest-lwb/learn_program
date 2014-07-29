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

// Problem Reader and Writer
char buffer[8];
Semaphore emptyBuffers(8);
Semaphore fullBuffers(0);

int main()
{
	ITP(false);
	ThreadNew("Writer", Writer, 0);
	ThreadNew("Reader", Reader, 0);
	RunAllThreads();
	return 0;
}

void Writer()
{
	for(int i=0; i<40; i++){
		char c = PrepareRandomChar();
		SemaphoreWait(emptyBuffers);
		buffer[i%8] = c;
		SemaphoreSignal(fullBuffers);
	}
}

void Reader()
{
	for(int i=0; i<40; i++){
		SemaphoreWait(fullBuffers);
		char c = buffer[i%8];		
		SemaphoreSignal(emptyBuffers);
		ProcessChar(c);
	}
}
