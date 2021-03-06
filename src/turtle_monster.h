//-----------------------------------------------------------------------------
// Copyright (c) 2013 @hirodotexe. All rights reserved.
//-----------------------------------------------------------------------------

#ifndef SUPER_MORIO_BROS_TURTLE_MONSTER_H_
#define SUPER_MORIO_BROS_TURTLE_MONSTER_H_

#include "moving_object.h"

class TurtleMonster : public MovingObject {
public:
  enum State {
    kWalking = 0,
    kGuarding = 2,
    kAttacking = 3,
    kNumStates,
  };

  TurtleMonster(int id_x, int id_y)
      : MovingObject(kTurtleMonster, 32, 32, id_x, id_y) {}

  virtual void Reset() {
    MovingObject::Reset();
    state_ = kWalking;
  }
  virtual void NotifyAttacked();

private:
  virtual int CalculateImageId() const;
  virtual void CalculateForce();

  State state_;
};

#endif  // SUPER_MORIO_BROS_TURTLE_MONSTER_H_