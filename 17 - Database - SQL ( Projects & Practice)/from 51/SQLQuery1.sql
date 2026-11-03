----51

select Employees.Name, Employees.ManagerID, Employees.Salary , Managers.Name AS ManagerName
from Employees inner join Employees as Managers on 
Employees.ManagerID = Managers.EmployeeID;


----52

select Employees.Name, Employees.ManagerID, Employees.Salary , Managers.Name AS ManagerName
from Employees left join Employees as Managers on 
Employees.ManagerID = Managers.EmployeeID;

----53

select Employees.Name, Employees.ManagerID, Employees.Salary ,
case 
	when Managers.Name is null then Employees.Name
	Else Managers.Name 
End AS ManagerName

from Employees left join Employees as Managers on 
Employees.ManagerID = Managers.EmployeeID;


----54
select Employees.Name, Employees.ManagerID, Employees.Salary , Managers.Name AS ManagerName
from Employees inner join Employees as Managers on 
Employees.ManagerID = Managers.EmployeeID

where Managers.Name='Mohammed';