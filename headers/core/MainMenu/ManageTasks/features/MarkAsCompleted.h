#include "UpdateTask.h"

class MarkAsCompleted : public UpdateTask {
public:
    static int _MarkAsCompleted();
};

int MarkAsCompleted::_MarkAsCompleted() {
   return updateTask_IsCompletedMember_MarkAsCompleted();
}