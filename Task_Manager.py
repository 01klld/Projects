tasks = []

def main():
    """
    Main function to display the menu and handle user choices.
    """
    # Menu options displayed to the user
    messages = """
1. Add tasks to a list
2. Mark the task as complete
3. View tasks
4. Quit
"""
    while True:
        print(messages)
        choice = input("Enter your choice: ")

        if choice == "1":
            add_task()
        elif choice == "2":
            mark_task_complete()
        elif choice == "3":
            view_tasks()
        elif choice == "4":
            break
        else:
            print("Invalid choice, please enter a number between 1 and 4")

def add_task():
    """
    Function to add a new task to the task list.
    """
    # Get a task from the user
    task = input("Enter a task: ")
    note = input("Enter your notes: ")
    # Define task status and details
    task_info = {"task": task, "Completed": False, "Notes": note}
    # Add task to the list
    tasks.append(task_info)
    print("Your task has been added successfully!")

def mark_task_complete():
    """
    Function to mark a task as complete.
    """
    # Get a list of incomplete tasks
    incomplete_tasks = [task for task in tasks if not task["Completed"]]
    # Show incomplete tasks to the user
    if not incomplete_tasks:
        print("You have no tasks to complete.")
        return
    for i, task in enumerate(incomplete_tasks, 1):
        print(f"{i}- {task['task']}")
        print("-" * 35)
    # Get the task number from the user to mark as complete
    try:
        task_number = int(input("Enter the number of the task to complete: "))
        if task_number < 1 or task_number > len(incomplete_tasks):
            print("Invalid task number")
            return
        # Mark the task as complete
        incomplete_tasks[task_number - 1]["Completed"] = True
        print("Task marked as complete")
    except ValueError:
        print("Invalid input, please enter a number.")

def view_tasks():
    """
    Function to view all tasks and their statuses.
    """
    # If there are no tasks, print a message and return
    if not tasks:
        print("No tasks to view.")
        print("-" * 35)
        return

    # Display all tasks with their status and notes
    for i, task in enumerate(tasks, 1):
        status = "✅" if task["Completed"] else "❌"
        print(f'{i}. {task["task"]} - {status}')
        print(f'Notes: {task["Notes"]}')
        print("-" * 35)

if __name__ == "__main__":
    main()
