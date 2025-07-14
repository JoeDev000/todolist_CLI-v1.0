#include "UpdateTask.h"

class UndoCompletedTask : public UpdateTask {
public:
    static int _UndoCompletedTask();
};

int UndoCompletedTask::_UndoCompletedTask() {
   return updateTask_IsCompletedMember_UndoCompleted();
}