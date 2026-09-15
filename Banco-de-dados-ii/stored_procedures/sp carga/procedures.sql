------------------------------
-- Item 2: Criar manualmente 5 divisões (division): IT, Marketing, HR, Sales e Product Development (sem head)

INSERT INTO division (name, ssnhead) VALUES ('IT', NULL);
INSERT INTO division (name, ssnhead) VALUES ('Marketing', NULL);
INSERT INTO division (name, ssnhead) VALUES ('HR', NULL);
INSERT INTO division (name, ssnhead) VALUES ('Sales', NULL);
INSERT INTO division (name, ssnhead) VALUES ('Product Development', NULL);

------------------------------
-- Item 3: Criar com uso de stored procedures alguns departamentos (dept). Randomicamente, incluir de 4 a 6 departamentos por divisão (sem gerente)

create or replace procedure sp_criar_departamentos() language plpgsql
as $$
declare
    v_iddiv   integer;
    v_name    varchar(30);
    qtd_dept  integer;
    i         integer;
    nome_dept varchar(30);
begin
    for v_iddiv, v_name in select iddiv, name from division loop

        qtd_dept := floor(random() * (6 - 4 + 1) + 4)::integer;

        for i in 1..qtd_dept loop
            nome_dept := v_name || ' - Dept ' || i;
            insert into dept (name, nemp, iddiv, ssnmngr)
            values (nome_dept, 0, v_iddiv, null);
        end loop;

    end loop;
end; $$;

-----------------------------
-- Item 5: Stored procedure para incluir funcionários (employee) - definir o número de funcionários por departamento (aleatoriamente é melhor, definindo um mínimo e um máximo)

CREATE OR REPLACE PROCEDURE inserir_employee(min_emp int, max_emp int)
AS $$
DECLARE
    reg_dept record;
    qtd_emp int;
    atual_ssn int;
    iterador int;
BEGIN
    SELECT MAX(ssn) INTO atual_ssn FROM employee;
    
    IF atual_ssn IS NULL THEN
        atual_ssn := 0;
    END IF;

    FOR reg_dept IN SELECT iddept FROM dept LOOP
        qtd_emp := (random() * (max_emp - min_emp))::int + min_emp;

        FOR iterador IN 1 .. qtd_emp LOOP
            atual_ssn := atual_ssn + 1;
            
            INSERT INTO employee (ssn, name, salary, iddept)
            VALUES (atual_ssn, 'Funcionario ' || atual_ssn, (random() * 5000 + 2000)::numeric(10,2), reg_dept.iddept);
        END LOOP;

        UPDATE dept SET nemp = nemp + qtd_emp WHERE iddept = reg_dept.iddept;
    END LOOP;
END;
$$ LANGUAGE plpgsql;

CALL inserir_employee(5, 5); -- coloque aqui o número de employee para utilizar o random por dept

------------------------------
-- Item 6: Stored procedure para as carreiras (career) e associação das carreiras com osfuncionários (emp_career).

-- Stored procedure pras carreiras (career)

CREATE OR REPLACE PROCEDURE inserir_career(
    p_dscr VARCHAR(20),
    p_minvalue NUMERIC(10,2),
    p_maxvalue NUMERIC(10,2)
)
LANGUAGE plpgsql AS $$

BEGIN
    INSERT INTO career (dscr, minvalue, maxvalue)
    VALUES(p_dscr, p_minvalue, p_maxvalue);
END;
$$;


-- Associacao das carreiras com os funcionarios (emp_career)

CREATE OR REPLACE PROCEDURE inserir_emp_career(
    p_ssn INTEGER,
    p_idcar INTEGER,
    p_startdt DATE,
    p_enddt DATE
)
LANGUAGE plpgsql AS $$

BEGIN
    INSERT INTO emp_career (ssn, idcar, startdt, enddt)
    VALUES(p_ssn, p_idcar, p_startdt, p_enddt);
END;
$$;

