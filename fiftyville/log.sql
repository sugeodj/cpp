-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Begin by checking the crime reports for the day that the crime took place
select * from crime_scene_reports where year = 2021 and month = 7 and day = 28 and street = 'Humphrey Street';
-- Time: 10:15am

-- View the interviews conducted on the same day
select * from interviews where year = 2021 and month = 7 and day = 28;
-- People interviewed: Ruth, Eugene, Raymond

-- View phone logs
select * from phone_calls where year = 2021 and month = 7 and day = 28 and duration < 60;


-- View the earliest flight leaving fiftyville the next morning
select * from flights f join airports a on a.id = f.destination_airport_id where year = 2021 and month = 7 and day = 29 order by hour asc;
-- Flight ID = 36

-- Find the passengers on the flight
select * from people p1 join passengers p2 on p2.passport_number = p1.passport_number join flights f on f.id = p2.flight_id where f.id = 36;
-- Doris
-- Sofia
-- Bruce
-- Edward
-- Kelsey
-- Taylor
-- Kenny
-- Luca

-- View the bakery security logs to ddiscover the assailant
select * from bakery_security_logs where year = 2021 and month = 7 and day = 28 order by hour;
-- 5P2BI95
-- 94KL13X
-- 6P58WS2
-- 4328GD8
-- G412CB7
-- L93JTIZ
-- 322W7JE
-- 0NTHK55
-- 1106N58

-- Figure out who is the thief
SELECT name FROM people

-- Query courthouse security logs table for the license plate
WHERE people.license_plate IN (
    SELECT license_plate FROM courthouse_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25)

-- Query ATM transactions and bank accounts tables for bank account number
AND people.id IN (
    SELECT person_id FROM bank_accounts
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28
    AND transaction_type = “withdraw”
    AND atm_transactions.atm_location = “Leggett Street”)

-- Query phone calls table for phone number
AND people.phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28
    AND duration < 60)

-- Query flights and passengers tables for passport number
AND people.passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id IN (
        SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29
        ORDER BY hour, minute ASC LIMIT 1));


-- FIgure out who helped the thief
SELECT name FROM people
WHERE phone_number IN (
    SELECT receiver FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28
    AND caller = (
        SELECT phone_number FROM people WHERE name = “Ernest”)
    AND duration < 60);