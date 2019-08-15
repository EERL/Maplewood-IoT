typedef struct WATTNODE_DEV
{
  uint8_t id;
  uint16_t CT_A;
  uint16_t CT_B;
  uint16_t CT_C;
  uint8_t Phases;
  uint8_t dir;
  WATTNODE_DEV(){WATTNODE_DEV(1,200,200,200,3,0,0,0);}
  WATTNODE_DEV(uint8_t id_, uint16_t CT_A_, uint16_t CT_B_, uint16_t CT_C_, uint8_t P, uint8_t d_a,
  uint8_t d_b, uint8_t d_c){
    CT_A = CT_A_;
    CT_B = CT_B_;
    CT_C = CT_C_;
    Phases = P;
    id = id_;
    set_dir(d_a, d_b, d_c);
  }

  void set_dir(bool A, bool B, bool C){
    dir = (A&0x1)|((B&0x1)<<1)|((C&0x1)<<2);
  }
};

/**
 * Queue for storing all the requests
 */

class Wattnode_Queue {
  private:
    WATTNODE_DEV *Queue;
    uint32_t curr_dev = 0;
    uint32_t queue_counter = 0;
    uint32_t queue_max = 0;
  public:
    Wattnode_Queue(uint8_t size) {Queue = new WATTNODE_DEV[size]; queue_max = size;}
  
    void enqueue(WATTNODE_DEV dev){
      if (queue_counter < queue_max)
        Queue[queue_counter++] = dev;
    }

    void dequeue(WATTNODE_DEV dev){
      //Not really needed
    }

    /**
     * Can only be called after we setup the queue
     */
    WATTNODE_DEV cycle(){
      if (curr_dev >= queue_max) queue_counter = 0;
      return Queue[curr_dev++];
    }
};