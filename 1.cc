// problem.id: 1; author.name: Yuchen Hou;

int parallel_add (unsigned p, unsigned myrank, int partial_sum)
{
  int stage = (int) log2( p ) - 1; // remaining stage count toward the end of calculation
  unsigned node_count = 0;
  for (; (stage > 0) && (myrank > node_count); stage--)
    {
      node_count = (unsigned) 2^stage; // remaining active node in the calculation
      unsigned sender_id = myrank + node_count;
      int incomming_summand = 0;
      receive( sender_id, incomming_summand );
      partial_sum += incomming_summand;
    }
  if (myrank != 0)
    {		  // a non-root nodes submits its partial sum and return
      unsigned receiver_id = myrank - node_count;
      send( receiver_id, partial_sum );
      return 0;
    }
  else
    {		  // root-node return its partial sum as the total sum
      return partial_sum;
    }
}
