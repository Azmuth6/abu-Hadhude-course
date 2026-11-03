select * from VehicleMasterDetails;

----2
select * from VehicleDetails
where Year between 1950 and  2000
order  by year;

----3
select count(*) from VehicleDetails
where Year between 1950 and  2000;

----4
select Makes.Make,count(*) as NumOfVehicle
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and  2000
group by Makes.Make
order by NumOfVehicle desc;

----5
select Makes.Make,count(*) as NumOfVehicle
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and  2000 
group by Makes.Make
having count(*) > 12000
order by NumOfVehicle desc;

--without  having 

select * from 
(
	select Makes.Make,count(*) as NumOfVehicle
	from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
	where Year between 1950 and  2000 
	group by Makes.Make
)R1

where NumOfVehicle > 12000
order by NumOfVehicle desc;



----6

select Makes.Make,count(*) as NumOfVehicle ,( select count(*) from VehicleDetails)as totalVehicle
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and  2000 
group by Makes.Make 
order by NumOfVehicle desc;


----7

select Makes.Make,count(*) as NumOfVehicle ,( select count(*) from VehicleDetails)as totalVehicle,
cast (count(*) as float) / cast( ( select count(*) from VehicleDetails) as float) as persentage
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and  2000 
group by Makes.Make 
order by NumOfVehicle desc;

--

select * , cast (NumOfVehicle as float) / cast(totalVehicle as float) as persentage

from (
	select Makes.Make,count(*) as NumOfVehicle ,( select count(*) from VehicleDetails)as totalVehicle
	from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
	where Year between 1950 and  2000 
	group by Makes.Make 
)R1
order by NumOfVehicle desc;


----8
select Makes.Make , FuelTypes.FuelTypeName ,count(*) as NumOfVehicle
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
     inner join FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID

group by Makes.Make ,FuelTypes.FuelTypeName 
order by Makes.Make;


----9

select * , FuelTypes.FuelTypeName as jd
from VehicleDetails
inner join FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
where (FuelTypes.FuelTypeName = N'Gas');


----10

select distinct Makes.Make , FuelTypes.FuelTypeName
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
     inner join FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID

where FuelTypes.FuelTypeName = N'GAS'
order by Makes.Make;

----11 
select count (distinct Makes.Make) as total
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
     inner join FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID

where FuelTypes.FuelTypeName = N'GAS';

--
select count(*) from
(
	select distinct Makes.Make , FuelTypes.FuelTypeName
	from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
	     inner join FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
	
	where FuelTypes.FuelTypeName = N'GAS'
)R1

----12
select Makes.Make , count (*) as total
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
group by Makes.Make 
order by count(*) desc;

----13
select Makes.Make , count (*) as total
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
group by Makes.Make 
having count(*) > 20000
order by count(*) desc;

----14
select Make from Makes 
where Make like 'B%';

----15
select Make from Makes 
where Make like '%W';


----16
select distinct Makes.Make, DriveTypes.DriveTypeName
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
inner join DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID

where DriveTypes.DriveTypeName = 'FWD';


----17
select count(*) from
(
	select distinct Makes.Make, DriveTypes.DriveTypeName
	from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
	inner join DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
	
	where DriveTypes.DriveTypeName = 'FWD'
)R1;

----18
SELECT        distinct Makes.Make, DriveTypes.DriveTypeName, Count(*) AS Total
FROM            DriveTypes INNER JOIN
                         VehicleDetails ON DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID INNER JOIN
                         Makes ON VehicleDetails.MakeID = Makes.MakeID

Group By Makes.Make, DriveTypes.DriveTypeName

Order By Make ASC, Total Desc

----19
select distinct Makes.Make, DriveTypes.DriveTypeName , count(*) as total
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
inner join DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID

group by Makes.Make, DriveTypes.DriveTypeName
having  count(*) >10000
Order By Make ASC, Total Desc ;


----20
select *  from VehicleDetails
where NumDoors is NULL;

----21
select count(*)  from VehicleDetails
where NumDoors is NULL;

----22
select (
cast (( select count(*)  from VehicleDetails where NumDoors is NULL) as float)

/

cast ((select count(*)  from VehicleDetails) as float )

)  as persentage


----23
SELECT distinct    VehicleDetails.MakeID, Makes.Make, SubModelName
from 
VehicleDetails inner join 
			   Makes on VehicleDetails.MakeID =  Makes.MakeID 
			   inner join 
			   SubModels on VehicleDetails.SubModelID = SubModels.SubModelID

where SubModelName='Elite';


----24
select * from VehicleDetails
where NumDoors  = 2 and Engine_Liter_Display > 3;

----25
select * , Makes.Make
from VehicleDetails 
inner join Makes on VehicleDetails.MakeID =  Makes.MakeID

where engine like  '%OHV%' and engine_Cylinders = 4;


----26
select * , Bodies.BodyName
from VehicleDetails inner join 
Bodies on VehicleDetails.BodyID = Bodies.BodyID
where Bodies.BodyName = 'Sport Utility' and year > 2021;

----27
select * , Bodies.BodyName
from VehicleDetails inner join 
Bodies on VehicleDetails.BodyID = Bodies.BodyID
where Bodies.BodyName in ('Sport Utility' , 'Hatchback' , 'Sedan' );

----28
select * , Bodies.BodyName
from VehicleDetails inner join 
Bodies on VehicleDetails.BodyID = Bodies.BodyID
where Bodies.BodyName in ('Sport Utility' , 'Hatchback' , 'Sedan' ) 
	 and Year in (2008 , 2020 , 2021);

----29
select found =1
where exists 
(
	select top 1 * from VehicleDetails where Year = 1950
);


----30

select vehicle_Display_Name , NumDoors ,
CASE
    WHEN NumDoors = 2 THEN 'Two'
    WHEN NumDoors = 4 THEN 'foure'
    WHEN NumDoors = 3 THEN 'three'
	WHEN NumDoors = 8 THEN 'eight'
	WHEN NumDoors = 1 THEN 'one'
	WHEN NumDoors = 5 THEN 'five'
	WHEN NumDoors = 6 THEN 'sex'
	WHEN NumDoors = 0 THEN 'zero'
	WHEN NumDoors is Null THEN 'not set'
    ELSE 'unkown'
END as Decription_Of_DoorNum

from VehicleDetails;


----31
select vehicle_Display_Name , year ,Age =  Year(GetDate())-Year 
from VehicleDetails
order by Age desc;


----32
select vehicle_Display_Name , year ,Age =  Year(GetDate())-Year 
from VehicleDetails
where (Year(GetDate())-Year)  between 15 and 25
order by Age desc;

----33
select min(Engine_CC) , Max (Engine_CC) , Avg(Engine_CC)
from VehicleDetails;

----34
select vehicle_Display_Name 
from VehicleDetails
where Engine_CC = (select min(Engine_CC) from VehicleDetails);

----35
select vehicle_Display_Name 
from VehicleDetails
where Engine_CC = (select max(Engine_CC) from VehicleDetails);

----36
select vehicle_Display_Name 
from VehicleDetails
where Engine_CC < (select avg(Engine_CC) from VehicleDetails);

----37

select count(*) from 
(
select vehicle_Display_Name 
from VehicleDetails
where Engine_CC > (select avg(Engine_CC) from VehicleDetails)
)R1;


----38
select distinct Engine_CC
from VehicleDetails
order by Engine_CC desc;

----39
select distinct top 3 Engine_CC
from VehicleDetails
order by Engine_CC desc;

----40
select vehicle_Display_Name 
from VehicleDetails
where Engine_CC in 
(
	select distinct top 3 Engine_CC
	from VehicleDetails
	order by Engine_CC desc
);

----41
select distinct  makes.make 
from VehicleDetails inner join makes on VehicleDetails.MakeID = makes.MakeID
where Engine_CC in 
(
	select distinct top 3 Engine_CC
	from VehicleDetails
	order by Engine_CC desc
)
Order By Make;


----42
select Engine_CC,
CASE
    WHEN Engine_CC between 0 and 1000 THEN 100
    WHEN Engine_CC between 1001 and 2000 THEN 200
    WHEN Engine_CC between 2001 and 4000 THEN 300
	WHEN Engine_CC between 4001 and 6000 THEN 400
	WHEN Engine_CC between 6001 and 8000 THEN 500
	WHEN Engine_CC > 8000 THEN 600
    ELSE 0
END as Tax

from 
(
	select distinct Engine_CC from VehicleDetails
) R1
order by Engine_CC;

----43
select Makes.Make , sum (NumDoors) as TotalNumberOfDoors
from VehicleDetails inner join Makes on
VehicleDetails.MakeID = Makes.MakeID

group by Makes.Make
Order By TotalNumberOfDoors desc;

----44
select Makes.Make , sum (NumDoors) as TotalNumberOfDoors
from VehicleDetails inner join Makes on
VehicleDetails.MakeID = Makes.MakeID

group by Makes.Make
having Makes.Make = 'Ford';

----45
select Makes.Make , count (*) as NumberOfModels
from Makes inner join MakeModels on 
Makes.MakeID = MakeModels.MakeID

group by Makes.Make
Order By NumberOfModels Desc;

----46
select top 3 Makes.Make , count (*) as NumberOfModels
from Makes inner join MakeModels on 
Makes.MakeID = MakeModels.MakeID

group by Makes.Make
Order By NumberOfModels Desc


----47

select max(NumberOfModels)  as MaxNumberOfModels
from
(
select Makes.Make , count (*) as NumberOfModels
from Makes inner join MakeModels on 
Makes.MakeID = MakeModels.MakeID
group by Makes.Make

)R1;

----48
select Makes.Make , count (*) as NumberOfModels
from Makes inner join MakeModels on 
Makes.MakeID = MakeModels.MakeID

group by Makes.Make

having count (*) =
(
select max(NumberOfModels)  as MaxNumberOfModels
from
(
select Makes.Make , count (*) as NumberOfModels
from Makes inner join MakeModels on 
Makes.MakeID = MakeModels.MakeID
group by Makes.Make

)R1
);

----49
select Makes.Make , count (*) as NumberOfModels
from Makes inner join MakeModels on 
Makes.MakeID = MakeModels.MakeID

group by Makes.Make

having count (*) =
(
select min(NumberOfModels)  as minNumberOfModels
from
(
select Makes.Make , count (*) as NumberOfModels
from Makes inner join MakeModels on 
Makes.MakeID = MakeModels.MakeID
group by Makes.Make

)R1
);

----50
-- Get all FuelTypes , each time the result should be showed in random order
-- Note that the NewID() function will generate GUID for each row 

select * from FuelTypes
order by NEWID();